// Pure Virtual Functions and Abstract Classes
// A pure virtual function is a virtual function with no implementation in the base class. A class containing at least one pure virtual function is called an abstract class and cannot be instantiated.

#include <iostream>

class Shape {
public:
    // Pure virtual function
    virtual void draw() const = 0;  
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() {
    Shape* shapePtr;

    Circle circle;
    Square square;

    // Point to Circle object
    shapePtr = &circle;
    shapePtr->draw();  // Calls Circle's draw()

    // Point to Square object
    shapePtr = &square;
    shapePtr->draw();  // Calls Square's draw()
    
    return 0;
}