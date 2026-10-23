# Exercise: Social Network of Friends

Create two classes, `User` and `Network`, that model a mini social network where friendship is **mutual** (if Ana is a friend of Luis, Luis is a friend of Ana). This creates cycles between users: your job is to make sure that removing someone leaves no memory leaks and no dangling pointers.

## Requirements

1. **`User`**: has a name (`m_name`) and a list of friends (`m_friends`).
2. **`User` constructor and destructor**: the constructor prints `User 'Ana' created` and the destructor prints `User 'Ana' deleted`, so you can see when each one happens.
3. **`Network` is the sole owner of the users**: it manages their lifetime and stores them by name.
4. **`Network::addUser(name)`**: creates a user and registers it in the network.
5. **`Network::getUser(name)`**: returns a **non-owning** pointer to the user, or `nullptr` if it does not exist.
6. **`Network::makeFriends(a, b)`**: establishes a mutual friendship between two users (by name). Returns `bool`: `true` if the friendship was created, `false` if either user does not exist.
7. **`Network::removeUser(name)`**: removes the user from the network. Its destructor must run **at that very moment**, even if other users still have it in their friend list.
8. **`User::printFriends() const`**: prints only the friends that **still exist**, with the format `Friends of Marta: Ana, Luis, Pablo`. A deleted friend must not appear or cause a crash.
9. **`User::countFriends() const`**: returns how many friends still exist.
10. **Edge cases**: befriending yourself or repeating an existing friendship must not create duplicate entries (`makeFriends` returns `false`).
11. **Choice of pointers**: decide which type of smart pointer each relationship uses (network → users and users → friends) and justify it in a comment.

## `main` to test it

```cpp
int main() {
    {
        Network net;

        net.addUser("Ana");      // User 'Ana' created
        net.addUser("Luis");     // User 'Luis' created
        net.addUser("Marta");    // User 'Marta' created
        net.addUser("Pablo");    // User 'Pablo' created

        net.makeFriends("Ana", "Luis");
        net.makeFriends("Ana", "Marta");
        net.makeFriends("Luis", "Marta");
        net.makeFriends("Marta", "Pablo");

        net.getUser("Marta")->printFriends();   // Friends of Marta: Ana, Luis, Pablo

        net.removeUser("Luis");                 // User 'Luis' deleted

        net.getUser("Ana")->printFriends();     // Friends of Ana: Marta
        net.getUser("Marta")->printFriends();   // Friends of Marta: Ana, Pablo

        std::cout << net.getUser("Ana")->countFriends() << std::endl;    // 1
        std::cout << net.getUser("Marta")->countFriends() << std::endl;  // 2

        std::cout << net.makeFriends("Ana", "Luis") << std::endl;        // 0 (Luis no longer exists)
        std::cout << net.makeFriends("Ana", "Marta") << std::endl;       // 0 (already friends)
        std::cout << net.makeFriends("Ana", "Ana") << std::endl;         // 0 (yourself)
    }   // the network is destroyed here: Ana, Marta and Pablo are deleted (order unspecified)

    return 0;
}
```

## Questions to think about when you finish

- **The key experiment:** change the friend list so it uses `shared_ptr` in both directions and run it again. Which destructors run at the end? And when calling `removeUser`?
- What happens to the expired `weak_ptr`s left in the friend lists? When and how would you clean them up?
- Why is it better for `Network` to be the sole owner of the users, instead of the users owning each other?

## Optional extension

Add `mutualFriends(a, b)`, which returns the friends two users have in common. Think about which type it should return so that it does not extend anyone's lifetime unnecessarily.