#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>

class User{
    std::string m_name;
    std::vector<std::weak_ptr<User>> m_friends;

public:
    //Lets define the Constructor and Destructor
    User(std::string name) :m_name(name){
        std::cout << "User '" << name << "' created" << std::endl;
    }

    ~User(){
        std::cout << "User '" << m_name << "' deleted" << std::endl; 
    }

    std::string getName() const{
        return m_name;
    }

    bool addFriend(const std::shared_ptr<User>& fnd){
        for (const auto& w:m_friends){
            auto sp = w.lock();
            if (sp == fnd){
                return false;
            }
        }
        m_friends.push_back(fnd);
        return true;
    }

    void removeFriend(const std::shared_ptr<User>& other){
        for (auto it = m_friends.begin(); it != m_friends.end();){
            if(other == it -> lock()){
                it = m_friends.erase(it);
            }
            else{
                ++it;
            }
        }
    }

    int countFriends() const{
        int count = 0;
        for(auto p: m_friends){
            count += 1;
        }
        return count;
    }

    void printFriends() const{
        std::cout << "Friends of " << m_name << ": ";
        bool first = true;
        for(const auto& p: m_friends){
            auto sp = p.lock();
            if (sp){
                if(first){
                    std::cout << sp->getName();
                    first = false;
                }
                else{
                    std::cout << ", " << sp -> getName(); 
                }
            }
        }
        std::cout << std::endl;
    }
};

class Network{
    //Atribute -> A hashmap to save user name and the associated pointer
    std::map<std::string, std::shared_ptr<User>> users_in_net;
public:
    User* getUser(std::string name){
        auto p = users_in_net.find(name);
        if (p== users_in_net.end()){
            std::cout << "User not in Network"<< std::endl;
            return nullptr;
        }
        else{
            return p -> second.get();
        }
    }

    void addUser(std::string name){
        users_in_net[name]=std::make_shared<User>(name);  
    }

    bool makeFriends(std::string fnd1, std::string fnd2){
        if (fnd1 == fnd2){
            std::cout << "A user cannot be friends with themselves" << std::endl;
            return false;
        }
        auto fnd_n1 = users_in_net.find(fnd1);
        auto fnd_n2 = users_in_net.find(fnd2);
        if (fnd_n1== users_in_net.end()||fnd_n2 ==users_in_net.end()){
            std::cout << "One of the users not in the Network" << std::endl;
            return false;
        }
        bool mk_fnd = fnd_n1 -> second ->addFriend(fnd_n2->second);
        fnd_n2->second->addFriend(fnd_n1->second);
        return mk_fnd;
    }
    
    void removeUser(std::string name){
        auto fnd_name = users_in_net.find(name);
        if(fnd_name == users_in_net.end()){
            std::cout << "Unable to remove, as it is not in the Network" << std::endl;
            return;
        }
        for(const auto& del:users_in_net){
            del.second -> removeFriend(fnd_name -> second); 
        }
        users_in_net.erase(fnd_name);
        std::cout << "User " << name << " removed from the Network";
    }
};

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