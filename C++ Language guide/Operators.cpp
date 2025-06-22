#include <iostream>
using namespace std;

// Function to demonstrate arithmetic operators
void demoArithmeticOperators() {
    // Logic: Perform arithmetic operations
    int sum1 = 100 + 50;      // Addition
    int sum2 = sum1 + 250;    // Addition with variable
    int sum3 = sum2 + sum2;   // Addition of same variable
    int x = 10;
    x++;                      // Increment
    int product = sum1 * 2;   // Multiplication
    int quotient = sum2 / 2;  // Division
    int remainder = 17 % 5;   // Modulus
    cout << "Sum1: " << sum1 << endl;
    cout << "Sum2: " << sum2 << endl;
    cout << "Sum3: " << sum3 << endl;
    cout << "Incremented x: " << x << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl;
    cout << "Remainder: " << remainder << endl;
}

// Function to demonstrate assignment operators
void demoAssignmentOperators() {
    // Logic: Use compound assignment operators
    int x = 10;
    cout << "Initial x: " << x << endl;
    x += 5; // x = x + 5
    cout << "After += 5: " << x << endl;
    x *= 2; // x = x * 2
    cout << "After *= 2: " << x << endl;
    x -= 10; // x = x - 10
    cout << "After -= 10: " << x << endl;
}

// Function to demonstrate comparison operators
void demoComparisonOperators() {
    // Logic: Compare values and output boolean results
    int x = 5;
    int y = 3;
    cout << "x > y: " << (x > y) << endl;       // 1 (true)
    cout << "x == y: " << (x == y) << endl;     // 0 (false)
    cout << "x != y: " << (x != y) << endl;     // 1 (true)
    cout << "x <= y: " << (x <= y) << endl;     // 0 (false)
}

// Function to demonstrate logical operators
void demoLogicalOperators() {
    // Logic: Combine boolean expressions
    int x = 5;
    cout << "(x > 3 && x < 10): " << (x > 3 && x < 10) << endl; // 1 (true)
    cout << "(x > 3 || x < 4): " << (x > 3 || x < 4) << endl;   // 1 (true)
    cout << "!(x > 3): " << (!(x > 3)) << endl;                 // 0 (false)
}

// Function to demonstrate bitwise operators
void demoBitwiseOperators() {
    // Logic: Manipulate bits of integers
    int a = 5;    // Binary: 0101
    int b = 3;    // Binary: 0011
    cout << "a & b: " << (a & b) << endl;   // 0001 = 1
    cout << "a | b: " << (a | b) << endl;   // 0111 = 7
    cout << "a ^ b: " << (a ^ b) << endl;   // 0110 = 6
    cout << "~a: " << (~a) << endl;         // Inverts 0101 (e.g., -6 for 32-bit)
    cout << "a << 1: " << (a << 1) << endl; // 1010 = 10
    cout << "b >> 1: " << (b >> 1) << endl; // 0001 = 1
    int x = 5;
    x &= 3; // 0101 & 0011 = 0001
    cout << "x &= 3: " << x << endl;
    x |= 2; // 0001 | 0010 = 0011
    cout << "x |= 2: " << x << endl;
}

// Function to demonstrate other operators
void demoOtherOperators() {
    // Logic: Use comma and conditional operators
    int a, b;
    int x = (a=5, b=10, a+b); // Comma: x = 15
    int max = a > b ? a : b;  // Conditional: max = 10
    cout << "Comma result: " << x << endl;
    cout << "Conditional max: " << max << endl;
}

// Function to demonstrate system status checker
void demoSystemStatusChecker() {
    // Logic: Check system status with operators, including bitwise
    int status = 0; // No status
    const int POWER_ON = 1; // 0001
    const int ERROR = 2;    // 0010
    status |= POWER_ON;     // Set power on: 0001
    double temp = 75.5;
    const double TEMP_LIMIT = 80.0;
    bool isSafe = (status & POWER_ON) && (temp < TEMP_LIMIT);
    cout << "Status (bitwise): " << status << endl;
    cout << "Temperature: " << temp << endl;
    cout << "Is Safe: " << isSafe << endl;
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ Operators Demonstration ===" << endl;

    cout << "\n1. Arithmetic Operators:" << endl;
    demoArithmeticOperators();

    cout << "\n2. Assignment Operators:" << endl;
    demoAssignmentOperators();

    cout << "\n3. Comparison Operators:" << endl;
    demoComparisonOperators();

    cout << "\n4. Logical Operators:" << endl;
    demoLogicalOperators();

    cout << "\n5. Bitwise Operators:" << endl;
    demoBitwiseOperators();

    cout << "\n6. Other Operators:" << endl;
    demoOtherOperators();

    cout << "\n7. System Status Checker:" << endl;
    demoSystemStatusChecker();

    cout << "\n8. Exercise Answers:" << endl;
    cout << "Q1: Operators are used to: Answer: Perform operations on variables and values" << endl;
    cout << "Q2: Which logical operator returns true only if both conditions are true? Answer: && (Logical AND)" << endl;

    return 0;
}
