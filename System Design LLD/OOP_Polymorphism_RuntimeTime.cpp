/*
Polymorphism is the ability of an object to take on multiple forms. 
In C++, it is the ability of an object to behave in different ways depending on the context.

There are two types of polymorphism in C++:

1. Compile-time Polymorphism:
   - Function Overloading (same name, different parameters)
   - Operator Overloading (different symbols, but same operation)
   - Template Metaprogramming (code gets generated at compile time)

2. Runtime Polymorphism:
   - Function Overriding (same name, same parameters, different implementation)
   - Virtual Functions (child class provides different implementation than parent class)

*/

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual method → can be overridden
    virtual void makeSound() {
        cout << "Some generic animal sound" << endl;
    }

    virtual ~Animal() {} // Always use virtual destructor
};

// Derived class 1
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Dog says: Woof!" << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat says: Meow!" << endl;
    }
};

// Main function demonstrating Polymorphism
int main() {
    // Base class pointer
    Animal* a;

    // Pointing to Dog
    a = new Dog();
    a->makeSound();  // Outputs "Dog says: Woof!"

    // Pointing to Cat
    a = new Cat();
    a->makeSound();  // Outputs "Cat says: Meow!"

    delete a;

    return 0;
}

