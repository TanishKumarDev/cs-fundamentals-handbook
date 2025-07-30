#include <iostream>
#include <string>
using namespace std;

// ============================================================
// Common Interface (Base Class)
// ============================================================

class Vehicle {
public:
    virtual void drive() = 0;  // pure virtual function
};

// ============================================================
// Concrete Classes
// ============================================================

class TwoWheeler : public Vehicle {
public:
    void drive() override {
        cout << "Riding a Two-Wheeler" << endl;
    }
};

class FourWheeler : public Vehicle {
public:
    void drive() override {
        cout << "Driving a Four-Wheeler" << endl;
    }
};

class Truck : public Vehicle {
public:
    void drive() override {
        cout << "Driving a Truck" << endl;
    }
};

// ============================================================
// Main Function
// ============================================================

int main() {
    string type = "three";  // Change this to "two", "four", or "three" to test different vehicles
    Vehicle* vehicle = nullptr;

    if (type == "two") {
        vehicle = new TwoWheeler();
    } else if (type == "four") {
        vehicle = new FourWheeler();
    } else {
        vehicle = new Truck();
    }

    vehicle->drive();

    delete vehicle;  // clean up memory
    return 0;
}

/* ============================================================

👉 Problems: and Why its bad*

1. Code tightly depends on new TwoWheeler(), new FourWheeler(), and new Truck().

* If you add a new class like ThreeWheeler, you need to edit this code.

2. if-else everywhere

* Not scalable. Duplicated logic in every class needing objects.

3.  Breaks Open-Closed Principle

* You have to change existing code to add new types.

============================================================*/