#include <iostream>
using namespace std;

// Function to demonstrate basic enum usage
void demoBasicEnum() {
    // Logic: Declare an enum and print its value
    enum Level { LOW, MEDIUM, HIGH };
    enum Level myVar = MEDIUM;
    cout << "Enum value (MEDIUM): " << myVar << endl; // Outputs 1
}

// Function to demonstrate custom enum values
void demoCustomEnumValues() {
    // Logic: Assign custom values to enum items
    enum Level { LOW = 25, MEDIUM = 50, HIGH = 75 };
    enum Level myVar = MEDIUM;
    cout << "Custom enum value (MEDIUM): " << myVar << endl; // Outputs 50
}

// Function to demonstrate auto-incremented enum values
void demoAutoIncrementEnum() {
    // Logic: Show auto-increment from a custom value
    enum Level { LOW = 5, MEDIUM, HIGH };
    enum Level myVar = HIGH;
    cout << "Auto-incremented enum value (HIGH): " << myVar << endl; // Outputs 7
}

// Function to demonstrate enum in switch statement
void demoEnumSwitch() {
    // Logic: Use enum in a switch statement for readable code
    enum Level { LOW = 1, MEDIUM, HIGH };
    enum Level myVar = MEDIUM;
    switch (myVar) {
        case 1:
            cout << "Low Level" << endl;
            break;
        case 2:
            cout << "Medium Level" << endl;
            break;
        case 3:
            cout << "High Level" << endl;
            break;
    }
}

// Function to demonstrate traffic light system with enum
void demoTrafficLight() {
    // Logic: Simulate traffic light states with enum and switch
    enum TrafficLight { RED = 1, YELLOW, GREEN };
    enum TrafficLight light = YELLOW;
    switch (light) {
        case RED:
            cout << "Traffic Light: Stop" << endl;
            break;
        case YELLOW:
            cout << "Traffic Light: Prepare to stop" << endl;
            break;
        case GREEN:
            cout << "Traffic Light: Go" << endl;
            break;
    }
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ Enums Demonstration ===" << endl;

    cout << "\n1. Basic Enum Usage:" << endl;
    demoBasicEnum();

    cout << "\n2. Custom Enum Values:" << endl;
    demoCustomEnumValues();

    cout << "\n3. Auto-Incremented Enum Values:" << endl;
    demoAutoIncrementEnum();

    cout << "\n4. Enum in Switch Statement:" << endl;
    demoEnumSwitch();

    cout << "\n5. Traffic Light System:" << endl;
    demoTrafficLight();

    return 0;
}
