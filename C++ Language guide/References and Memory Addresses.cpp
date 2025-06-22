#include <iostream>
#include <string>
using namespace std;

// Function to demonstrate basic reference usage
void demoBasicReference() {
    // Logic: Create a reference and show it aliases the original variable
    string food = "Pizza";
    string &meal = food;
    cout << "Food: " << food << endl; // Outputs "Pizza"
    cout << "Meal: " << meal << endl; // Outputs "Pizza"
    meal = "Pasta"; // Modify via reference
    cout << "After changing meal, food: " << food << endl; // Outputs "Pasta"
}

// Function to demonstrate memory addresses
void demoMemoryAddress() {
    // Logic: Show that reference and variable share the same memory address
    string food = "Pizza";
    string &meal = food;
    cout << "Address of food: " << &food << endl; // Outputs address, e.g., 0x6dfed4
    cout << "Address of meal: " << &meal << endl; // Outputs same address
}

// Function to demonstrate reference in function parameter
void demoReferenceFunction() {
    // Logic: Use references to swap two variables
    int a = 5, b = 10;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    // Define swap function
    auto swapValues = [](int &x, int &y) {
        int temp = x;
        x = y;
        y = temp;
    };
    swapValues(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;
}

// Function to demonstrate practical string modification
void demoStringModifier() {
    // Logic: Modify a string via reference in a function
    string text = "Pizza";
    cout << "Before modification: " << text << endl;
    // Define modifier function
    auto modifyString = [](string &str) {
        str = "Burger";
    };
    modifyString(text);
    cout << "After modification: " << text << endl;
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ References and Memory Addresses Demonstration ===" << endl;

    cout << "\n1. Basic Reference Usage:" << endl;
    demoBasicReference();

    cout << "\n2. Memory Address Verification:" << endl;
    demoMemoryAddress();

    cout << "\n3. Reference in Function (Swap):" << endl;
    demoReferenceFunction();

    cout << "\n4. Practical String Modifier:" << endl;
    demoStringModifier();

    cout << "\n5. Exercise Answers:" << endl;
    cout << "Q1: What is a reference variable in C++?" << endl;
    cout << "Answer: A reference to an existing variable" << endl;
    cout << "Q2: What does the & operator return when used with a variable?" << endl;
    cout << "Answer: The memory address of the variable" << endl;

    return 0;
}