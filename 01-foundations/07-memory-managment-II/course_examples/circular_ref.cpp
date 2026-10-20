#include <iostream>
class Employee; //Forward declaration, so that the compiler knows it exists
class Project{
public:
    //Pointer to employee
    std::shared_ptr<Employee> m_emp;
    //Constructor and Destructor
    Project() {
        std::cout << "Project()" << std::endl;
    }
    ~Project() {
        std::cout << "~Project()" << std::endl;
    }
};

class Employee{
public:
    //Pointer to project
    std::weak_ptr<Project> m_prj;
    //Contructo and destructor
    Employee() {
        std::cout << "Employee()" << std::endl;
    }
    ~Employee() {
        std::cout << "~Employee()" << std::endl;
    }
};

int main(){
    std::shared_ptr<Employee>emp{new Employee{}};
    std::shared_ptr<Project>prj{new Project{}};

    emp->m_prj = prj;
    prj->m_emp=emp;
}

//The destructors are not called as the pointers point to each other.
//So, the Refernce count is not zero, and the pointers are not destroyed.
//Therefore, generating memory leaks.