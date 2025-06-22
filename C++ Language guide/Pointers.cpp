#include <iostream>
#include <string>
using namespace std;

// Function to demonstrate basic pointer creation
void demoBasicPointer() {
    // Logic: Create a pointer and show address and value
    string food = "Pizza";
    string* ptr = &food;
    cout << "Value of food: " << food << endl; // Outputs "Pizza"
    cout << "Address of food: " << &food << endl; // Outputs address, e.g., 0x6dfed4
    cout << "Pointer value (address): " << ptr << endl; // Outputs same address
}

// Function to demonstrate dereferencing
void demoDereference() {
    // Logic: Access value through pointer using dereference
    string food = "Pizza";
    string* ptr = &food;
    cout << "Pointer address: " << ptr << endl; // Outputs address
    cout << "Dereferenced value: " << *ptr << endl; // Outputs "Pizza"
}

// Function to demonstrate modifying via pointer
void demoModifyPointer() {
    // Logic: Change value through pointer and verify
    string food = "Pizza";
    string* ptr = &food;
    cout << "Original value: " << food << endl; // Outputs "Pizza"
    *ptr = "Hamburger"; // Modify via pointer
    cout << "New pointer value: " << *ptr << endl; // Outputs "Hamburger"
    cout << "New food value: " << food << endl; // Outputs "Hamburger"
}

// Function to demonstrate pointer in function
void demoPointerFunction() {
    // Logic: Use pointer to modify variable in function
    int value = 50;
    cout << "Before function: " << value << endl;
    // Define function
    auto modifyValue = [](int* ptr) {
        *ptr = 100;
    };
    modifyValue(&value);
    cout << "After function: " << value << endl; // Outputs 100
}

// Function to demonstrate array manipulation with pointer
void demoArrayPointer() {
    // Logic: Use pointer to modify array elements
    int arr[3] = {10, 20, 30};
    int* ptr = arr;
    cout << "Original array: ";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Modify array via pointer
    for (int i = 0; i < 3; i++) {
        *(ptr + i) += 5;
    }
    cout << "Modified array: ";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ Pointers Demonstration ===" << endl;

    cout << "\n1. Basic Pointer Creation:" << endl;
    demoBasicPointer();

    cout << "\n2. Dereferencing Pointer:" << endl;
    demoDereference();

    cout << "\n3. Modifying via Pointer:" << endl;
    demoModifyPointer();

    cout << "\n4. Pointer in Function:" << endl;
    demoPointerFunction();

    cout << "\n5. Array Manipulation with Pointer:" << endl;
    demoArrayPointer();

    return 0;
}