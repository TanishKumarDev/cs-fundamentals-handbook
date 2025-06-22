#include <iostream>
#include <string>
using namespace std;

// Function to demonstrate variable declaration and initialization
void demoDeclaration() {
    // Logic: Declare and initialize variables, assign later if needed
    int myNum = 15;
    cout << "Initialized int: " << myNum << endl;
    int myOtherNum;
    myOtherNum = 20;
    cout << "Assigned later: " << myOtherNum << endl;
}

// Function to demonstrate changing variable values
void demoChangeValue() {
    // Logic: Reassign a new value to a variable
    int myNum = 15;
    cout << "Original value: " << myNum << endl;
    myNum = 10;
    cout << "New value: " << myNum << endl;
}

// Function to demonstrate different data types
void demoDataTypes() {
    // Logic: Use various data types
    int myNum = 5;
    double myFloatNum = 5.99;
    char myLetter = 'D';
    string myText = "Hello";
    bool myBoolean = true;
    cout << "int: " << myNum << endl;
    cout << "double: " << myFloatNum << endl;
    cout << "char: " << myLetter << endl;
    cout << "string: " << myText << endl;
    cout << "bool: " << myBoolean << endl;
}

// Function to demonstrate displaying variables
void demoDisplayVariables() {
    // Logic: Combine text and variables for output
    string name = "John";
    int age = 35;
    double height = 6.1;
    cout << name << " is " << age << " years old and " << height << " feet tall." << endl;
}

// Function to demonstrate adding variables
void demoAddVariables() {
    // Logic: Add variables and store result
    int x = 5;
    int y = 6;
    int sum = x + y;
    cout << "Sum of " << x << " and " << y << ": " << sum << endl;
}

// Function to demonstrate multiple variable declarations
void demoMultipleVariables() {
    // Logic: Declare multiple variables, assign one value to many
    int x = 5, y = 6, z = 50;
    cout << "Multiple declarations sum: " << (x + y + z) << endl;
    int a, b, c;
    a = b = c = 50;
    cout << "One value to multiple sum: " << (a + b + c) << endl;
}

// Function to demonstrate identifiers
void demoIdentifiers() {
    // Logic: Compare descriptive vs. vague identifiers
    int minutesPerHour = 60; // Descriptive
    int m = 60;              // Vague
    cout << "Descriptive identifier: " << minutesPerHour << " minutes/hour" << endl;
    cout << "Vague identifier: " << m << endl;
}

// Function to demonstrate constants
void demoConstants() {
    // Logic: Use const to prevent value changes
    const int minutesPerHour = 60;
    cout << "Constant: " << minutesPerHour << " minutes/hour" << endl;
    // minutesPerHour = 70; // Error: assignment of read-only variable
}

// Function to demonstrate student data example
void demoStudentData() {
    // Logic: Store and display student information
    int studentID = 15;
    int studentAge = 23;
    float studentFee = 75.25;
    char studentGrade = 'B';
    cout << "Student ID: " << studentID << endl;
    cout << "Student Age: " << studentAge << endl;
    cout << "Student Fee: " << studentFee << endl;
    cout << "Student Grade: " << studentGrade << endl;
}

// Function to demonstrate rectangle area calculation
void demoRectangleArea() {
    // Logic: Calculate area of a rectangle
    int length = 4;
    int width = 6;
    int area = length * width;
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
    cout << "Area of rectangle: " << area << endl;
}

// Function to demonstrate temperature converter
void demoTemperatureConverter() {
    // Logic: Convert Celsius to Fahrenheit using a constant
    double celsius = 25.0;
    const double FAHRENHEIT_OFFSET = 32.0;
    double fahrenheit = celsius * 9.0 / 5.0 + FAHRENHEIT_OFFSET;
    cout << celsius << " Celsius = " << fahrenheit << " Fahrenheit" << endl;
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ Variables, Identifiers, and Constants Demonstration ===" << endl;

    cout << "\n1. Variable Declaration and Initialization:" << endl;
    demoDeclaration();

    cout << "\n2. Changing Variable Values:" << endl;
    demoChangeValue();

    cout << "\n3. Different Data Types:" << endl;
    demoDataTypes();

    cout << "\n4. Displaying Variables:" << endl;
    demoDisplayVariables();

    cout << "\n5. Adding Variables:" << endl;
    demoAddVariables();

    cout << "\n6. Multiple Variable Declarations:" << endl;
    demoMultipleVariables();

    cout << "\n7. Identifiers:" << endl;
    demoIdentifiers();

    cout << "\n8. Constants:" << endl;
    demoConstants();

    cout << "\n9. Student Data Example:" << endl;
    demoStudentData();

    cout << "\n10. Rectangle Area Calculation:" << endl;
    demoRectangleArea();

    cout << "\n11. Temperature Converter:" << endl;
    demoTemperatureConverter();

    cout << "\n12. Exercise Answer:" << endl;
    cout << "Q: Which is NOT a legal variable name?" << endl;
    cout << "Answer: int int = 20; (int is a reserved keyword)" << endl;

    return 0;
}