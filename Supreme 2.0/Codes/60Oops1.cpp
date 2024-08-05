#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    // Public attributes
    int id;
    int age;
    string name;

private:
    // Private attribute
    string portalPassword;

public:
    // Constructor to initialize attributes
    Student(int i, int n, string a, string p) : id(i), age(n), name(a), portalPassword(p) {};

    // Member function to display student details
    void display() {
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
        cout << "Student Age: " << age << endl;
    }
};

int main() {
    // Creating object of Student using normal initialization
    Student student1(101, 12345, "Lokesh", "password123");

    // Displaying details of student1
    cout << "Details of Student 1: ";
    cout<<student1.name<<endl;
    student1.display();
    cout << endl;

    // Creating object of Student using dynamic memory allocation
    Student* student2 = new Student(102, 54321, "Bhavesh", "securepassword");

    // Displaying details of student2
    cout << "Details of Student 2: ";
    cout<<student2->name<<endl;
    student2->display();

    // Deallocating memory allocated for student2
    delete student2;

    return 0;
}
