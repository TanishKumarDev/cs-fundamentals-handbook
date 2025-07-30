#include <iostream>
#include <string>
using namespace std;

// ============================================================
// Vehicle Interface (Base Class)
// ============================================================

class Vehicle {
public:
    virtual void drive() = 0;
    virtual ~Vehicle() {}  // Virtual destructor
};

// ============================================================
// Concrete Vehicle Classes
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
// Factory Class
// ============================================================

class VehicleFactory {
public:
    static Vehicle* createVehicle(const string& type) {
        if (type == "two") {
            return new TwoWheeler();
        } else if (type == "four") {
            return new FourWheeler();
        } else if (type == "truck") {
            return new Truck();
        } else {
            return nullptr;  // Or throw exception
        }
    }
};

// ============================================================
// Main Function
// ============================================================

int main() {
    // string type = "three";  // Change this to "two", "four", or "truck" to test different vehicles

    string type;
    // cout << "Enter vehicle type (two, four, truck): ";
    cin >> type;

    Vehicle* vehicle = VehicleFactory::createVehicle(type);
    if (vehicle) {
        vehicle->drive();
        delete vehicle;
    } else {
        cout << "Invalid vehicle type!" << endl;
    }

    return 0;
}

/* ============================================================

🧠 FACTORY DESIGN PATTERN — FULL EXPLANATION IN NOTES FORMAT

------------------------------------------------------------------------
✅ What Problem Does It Solve?
------------------------------------------------------------------------
When you have multiple object types (`TwoWheeler`, `Truck`, etc.), you often
write repetitive `if-else` logic in your main function or multiple files.

This creates 3 big issues:
1. Code Duplication — Same logic everywhere.
2. Tight Coupling — `main()` knows about all classes.
3. Poor Scalability — Add 1 new class? Change all places!

------------------------------------------------------------------------
🚫 WITHOUT FACTORY — Traditional Way (Tight Coupling)
------------------------------------------------------------------------

string type = "two";
Vehicle* vehicle = nullptr;

if (type == "two") 
    vehicle = new TwoWheeler();
else if (type == "four") 
    vehicle = new FourWheeler();
else 
    vehicle = new Truck();

🙅‍♂️ Disadvantages:
- `main()` directly uses `new` and knows every class.
- If new class added → you need to update `main()` logic.
- Breaks Open/Closed Principle (modifying existing code).

------------------------------------------------------------------------
✅ WITH FACTORY — Better Design (Loose Coupling)
------------------------------------------------------------------------

Vehicle* vehicle = VehicleFactory::createVehicle(type);

Advantages:
- `main()` doesn't care *how* the object is created.
- All object creation is handled inside the `VehicleFactory`.
- Add new class → only update factory, NOT `main()`.
- Follows Open/Closed Principle (Open for extension, closed for modification).

------------------------------------------------------------------------
🍕 Real-Life Analogy: Restaurant
------------------------------------------------------------------------

Without Factory:
Waiter goes to kitchen and cooks based on customer order.
He has to know how to cook every dish. 🙄

With Factory:
Waiter just says “I want a pizza”.
Chef handles what ingredients and how it’s made. 😌

So:
- `main()` = Waiter
- `Factory` = Chef
- `Concrete Classes` = Dishes
- `Factory Logic` = Recipe Book

------------------------------------------------------------------------
🧾 Comparison Table
------------------------------------------------------------------------

| Feature                  | Without Factory             | With Factory                 |
| ------------------------| --------------------------- | ----------------------------- |
| Who creates objects?    | `main()`                    | `VehicleFactory`              |
| `main()` knows classes? | YES                         | NO                            |
| Easy to extend?         | NO (edit everywhere)        | YES (only update factory)     |
| Scalable Design?        | NO                          | YES                           |
| OCP Followed?           | ❌                          | ✅                           |

------------------------------------------------------------------------
💡 One Line Summary:
------------------------------------------------------------------------
Factory Pattern moves object creation from the client (`main`) to a centralized factory class,
making code more scalable, cleaner, and easier to maintain.


------------------------------------------------------------------------
🔍 Key Differences vs Normal Version
------------------------------------------------------------------------

| Without Factory (Old)        | With Factory (New)              |
| ---------------------------- | ------------------------------- |
| `main()` decides object      | `VehicleFactory` decides object |
| Not scalable                 | Scalable — just edit factory    |
| Repeating `if-else` logic    | Centralized object creation     |
| Breaks Open/Closed Principle | Follows OCP                     |

------------------------------------------------------------------------
🧠 In Simple Words:
------------------------------------------------------------------------
Factory Pattern says: "Let one central place (factory) be responsible for creating objects. You just ask for the object — you don’t worry how it is created."

------------------------------------------------------------------------
🤔 Common Doubts
------------------------------------------------------------------------

1. Even after applying the Factory Design Pattern, you're still doing:

string type = "two"; // Manual Entry

Why is that still needed?
Because Factory Pattern only solves object creation, not how the input is chosen.
============================================================ */