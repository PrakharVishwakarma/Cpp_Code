#include <iostream>

using namespace std;

class Animal {
public:
    // Virtual function
    virtual void sound() const {
        cout << "Some generic animal sound" <<endl;
    }
};

class Dog : public Animal {
public:
    // Override the base class sound() method
    void sound() const override {
        cout << "Woof! Woof!" <<endl;
    }
};

class Cat : public Animal {
public:
    // Override the base class sound() method
    void sound() const override {
        cout << "Meow! Meow!" <<endl;
    }
};

int main() {
    Animal animal;
    animal.sound();

    Dog dog;
    dog.sound();
    Cat cat;
    cat.sound();

    Animal* animalPtr;
    // Point to Dog object
    animalPtr = &dog;
    animalPtr->sound();  // Calls Dog's sound()

    // Point to Cat object
    animalPtr = &cat;
    animalPtr->sound();  // Calls Cat's sound()
    
    return 0;
}
