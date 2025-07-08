#include <iostream>
using namespace std;

// Base class (Parent)
class Vehicle {
public:
    void start() {
        cout << "Vehicle started!" << endl;
    }

    void stop() {
        cout << "Vehicle stopped." << endl;
    }
};

// Derived class (Child) - inherits Vehicle
class Car : public Vehicle {
public:
    void openRoof() {
        cout << "Sunroof opened!" << endl;
    }
};

// Another child class
class Bike : public Vehicle {
public:
    void kickStart() {
        cout << "Bike kick started!" << endl;
    }
};

// Main function to demonstrate inheritance
int main() {
    Car myCar;
    myCar.start();       // inherited from Vehicle
    myCar.openRoof();    // specific to Car
    myCar.stop();        // inherited from Vehicle

    cout << "--------" << endl;

    Bike myBike;
    myBike.kickStart();  // specific to Bike
    myBike.start();      // inherited from Vehicle
    myBike.stop();       // inherited from Vehicle

    return 0;
}
// 🧠 What's Happening?
// Concept	Code
// Base class -	Vehicle with methods start() and stop()
// Child classes -	Car and Bike use inherited methods
// Code reuse -	start() and stop() are written once, used by all children
// New features -	Car adds openRoof(), Bike adds kickStart()

// ✅ Real-World Analogy:
// Common logic is written in a base class
// Then, create as many child classes as needed with customization options
// Similar to inheriting traits from parents 😄

// 🧪 Quick Test:
// Can you guess the output of this?

// Car c;
// c.start();
// c.stop();
// c.openRoof();

// Answer: All 3 methods will execute, with start() and stop() inherited from the parent, and openRoof() being specific to the child.

/*

/* Inheritance means:

A class (child) can inherit the properties and methods of another class (parent).

This leads to:
- Code reuse
- Creation of a hierarchy
- Easier addition of new features

Real Life Example:
Imagine you create a Vehicle class.
All vehicles have something in common: start(), stop()

Then you create specific types:

- Car
- Bike
- Truck

All have the same start() method — so write it in one place and reuse it.
That’s inheritance!
*/
