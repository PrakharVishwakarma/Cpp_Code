/*
Upcasting in Runtime Polymorphism

Upcasting is the process of treating a derived class object as if it were an object of the base class. In C++, upcasting is commonly used in the context of runtime polymorphism, where a base class pointer or reference is used to refer to an object of a derived class.
A pointer to a base class can hold the address of any derived class object. This is known as upcasting.

Downcasting is possible too in c++.
*/

#include <iostream>
using namespace std;

class Animal {
public:
    // Virtual function for runtime polymorphism
    virtual void sound() {
        cout << "Animal Sound Method called." << endl;
    }

    // Destructor to clean up resources; should be virtual
    // ~Animal() {
    //     cout << "Animal Destructor called" << endl;
    // }

    
    // Uncomment to make the destructor virtual
    virtual ~Animal() {
        cout << "Animal Destructor called" << endl;
    }
    
};

class Dog : public Animal {
public:
    // Override sound method for Dog
    void sound() override { 
        cout << "Dog's Sound Method called." << endl;
    }

    // Destructor
    ~Dog() {
        cout << "Dog's Destructor called" << endl;
    }
};

class Cat : public Animal {
public:
    // Override sound method for Cat
    void sound() {
        cout << "Cat's Sound Method called." << endl;
    }

    // Destructor
    ~Cat() {
        cout << "Cat's Destructor called" << endl;
    }
};

void sound(Animal *a) {
    // Upcasting allows calling the correct version of sound()
    a->sound();
}

int main() {
    // Upcasting: Treat Dog as an Animal
    Animal *a = new Dog;
    sound(a); // Outputs: Dog's Sound Method called.

    // Upcasting: Treat Dog as an Animal again
    a = new Dog;
    sound(a); // Outputs: Dog's Sound Method called.

    // Upcasting: Treat Cat as an Animal
    a = new Cat;
    sound(a); // Outputs: Cat's Sound Method called.

    // Destructor call
    delete(a); // Outputs: Cat's Destructor called (only if Animal's destructor is virtual{jiska object bana hai uskp override karke run time par call karna }).
    // Animal Destructor called (only if Animal's destructor is not virtual)
return 0;
}