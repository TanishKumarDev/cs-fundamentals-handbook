#include <iostream>
using namespace std;

// Abstract Base Class (acts like an interface)
class Car {
public:
    // Pure virtual functions = no implementation here → child must override
    virtual void startEngine() = 0;
    virtual void shiftGears(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;

    // Virtual destructor → ensures proper cleanup of derived object
    virtual ~Car() {}
};

// Derived Class — provides implementation for abstract methods
class SportsCar : public Car {
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

public:
    // Constructor: sets up initial values
    SportsCar(string b, string m)
        : brand(b), model(m), isEngineOn(false), currentSpeed(0), currentGear(0) {}

    // Implements abstract method
    void startEngine() override {
        isEngineOn = true;
        cout << brand << " " << model << " engine started with a roar!" << endl;
    }

    void shiftGears(int gear) override {
        if (!isEngineOn) {
            cout << "Engine is off. Cannot shift gears." << endl;
            return;
        }
        currentGear = gear;
        cout << "Shifted to gear " << gear << endl;
    }

    void accelerate() override {
        if (!isEngineOn) {
            cout << "Engine is off. Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << "Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake() override {
        if (currentSpeed > 0) {
            currentSpeed -= 20;
            if (currentSpeed < 0) currentSpeed = 0;
            cout << "Braking. Speed now " << currentSpeed << " km/h" << endl;
        } else {
            cout << "Already at rest." << endl;
        }
    }

    void stopEngine() override {
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << "Engine turned off." << endl;
    }
};

// Main function to demonstrate abstraction
int main() {
    // Abstraction: Using pointer to base class (Car)
    Car* myCar = new SportsCar("Ford", "Mustang");

    // User interacts only with abstract interface methods
    myCar->startEngine();
    myCar->shiftGears(1);
    myCar->accelerate();
    myCar->shiftGears(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    // Cleanup
    delete myCar;

    return 0;
}
