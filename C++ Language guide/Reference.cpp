#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function declarations
void printHeader(const string& title);
void demonstrateBasicReferences();
void demonstratePassByReference();
void modifyValue(int&); // Added declaration for modifyValue
void demonstrateReturnReference();
void demonstrateRangeBasedLoop();
void demonstrateCopyConstructor();
void demonstrateOperatorOverloading();
void demonstratePointerVsReference();
int& getMax(int& a, int& b);
void sayHello(); // For pointer vs. reference demo (function pointer)

// Class for copy constructor and operator overloading demos
class MyClass {
public:
    int value;
    MyClass(int v) : value(v) {}
    MyClass(const MyClass& other) : value(other.value) {
        cout << "Copy constructor called, value = " << value << endl;
    }
    MyClass& operator++() { // Prefix increment
        ++value;
        return *this;
    }
    int getValue() const { return value; }
};

int main() {
    // Call each function to demonstrate reference concepts
    printHeader("C++ References Demo");
    demonstrateBasicReferences();
    demonstratePassByReference();
    demonstrateReturnReference();
    demonstrateRangeBasedLoop();
    demonstrateCopyConstructor();
    demonstrateOperatorOverloading();
    demonstratePointerVsReference();
    return 0;
}

// Utility to print section headers
void printHeader(const string& title) {
    cout << "\n=== " << title << " ===\n";
}

// 1. Basic References
void demonstrateBasicReferences() {
    printHeader("Basic References");
    // Theory: A reference is an alias for a variable, sharing the same memory.
    // No dereferencing needed, unlike pointers.

    int x = 10;
    int& ref = x; // ref is an alias for x

    cout << "Value via ref: " << ref << endl; // 10
    ref = 22; // Modifies x
    cout << "Modified value of x via ref: " << x << endl; // 22

    // Output:
    // Value via ref: 10
    // Modified value of x via ref: 22
}

// 2. Passing Arguments by Reference
void demonstratePassByReference() {
    printHeader("Passing Arguments by Reference");
    // Theory: References allow functions to modify original variables without copying.

    int a = 10;
    cout << "Before: a = " << a << endl; // 10
    modifyValue(a);
    cout << "After: a = " << a << endl; // 20

    // Output:
    // Before: a = 10
    // After: a = 20
}

void modifyValue(int& x) {
    x = 20; // Modifies original variable
}

// 3. Returning Reference from Functions
void demonstrateReturnReference() {
    printHeader("Returning Reference from Functions");
    // Theory: Functions can return references to allow direct modification.
    // Avoid returning local variables to prevent dangling references.

    int x = 10, y = 20;
    int& maxVal = getMax(x, y);
    cout << "Before: x = " << x << ", y = " << y << endl; // x = 10, y = 20
    maxVal = 30; // Modifies y
    cout << "After: x = " << x << ", y = " << y << endl; // x = 10, y = 30

    // Output:
    // Before: x = 10, y = 20
    // After: x = 10, y = 30
}

int& getMax(int& a, int& b) {
    return (a > b) ? a : b;
}

// 4. References in Range-Based For Loops
void demonstrateRangeBasedLoop() {
    printHeader("References in Range-Based For Loops");
    // Theory: References in range-based loops allow direct modification of container elements.

    vector<int> vect{10, 20, 30, 40};
    for (int& x : vect) {
        x += 5; // Modify elements directly
    }
    cout << "Modified vector: ";
    for (int x : vect) {
        cout << x << " ";
    }
    cout << endl;

    // Output:
    // Modified vector: 15 25 35 45
}

// 5. References in Copy Constructor
void demonstrateCopyConstructor() {
    printHeader("References in Copy Constructor");
    // Theory: References are used in copy constructors to avoid infinite recursion.

    MyClass obj1(10);
    MyClass obj2 = obj1; // Calls copy constructor
    cout << "obj2 value: " << obj2.getValue() << endl;

    // Output:
    // Copy constructor called, value = 10
    // obj2 value: 10
}

// 6. References in Operator Overloading
void demonstrateOperatorOverloading() {
    printHeader("References in Operator Overloading");
    // Theory: References allow operator overloading to return modified objects efficiently.

    MyClass c(5);
    cout << "Before: count = " << c.getValue() << endl; // 5
    ++c; // Calls operator++
    cout << "After: count = " << c.getValue() << endl; // 6

    // Output:
    // Before: count = 5
    // After: count = 6
}

// 7. Pointers vs. References
void demonstratePointerVsReference() {
    printHeader("Pointers vs. References");
    // Theory: References are simpler and safer than pointers but less flexible.

    int x = 10;
    int* ptr = &x;
    int& ref = x;

    cout << "Pointer value: " << *ptr << endl; // 10
    cout << "Reference value: " << ref << endl; // 10
    ptr = nullptr; // Valid
    cout << "Pointer set to nullptr: " << ptr << endl;
    // ref = nullptr; // Invalid
    cout << "Reference cannot be nullptr, still: " << ref << endl;

    // Output:
    // Pointer value: 10
    // Reference value: 10
    // Pointer set to nullptr: 0
    // Reference cannot be nullptr, still: 10
}

// Function pointer for demo (used in pointer vs. reference)
void sayHello() {
    cout << "Hello from function pointer!" << endl;
}