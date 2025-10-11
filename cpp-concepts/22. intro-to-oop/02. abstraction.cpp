#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void accelerate() = 0;  // Pure virtual function
    virtual void brake() = 0;

    void startEngine() {
        cout << "Engine started!" << endl;
    }
};

class Car : public Vehicle {
public:
    void accelerate() override {
        cout << "Car: Pressing gas pedal..." << endl;
    }

    void brake() override {
        cout << "Car: Applying brakes..." << endl;
    }
};

int main() {
    Vehicle* myCar = new Car();
    myCar->startEngine();
    myCar->accelerate();
    myCar->brake();

    delete myCar;
    return 0;
}
