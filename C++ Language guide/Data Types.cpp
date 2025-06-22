#include <iostream>
#include <string>
using namespace std;

// Function to demonstrate numeric types
void demoNumericTypes() {
    // Logic: Show int, float, double, and scientific notation
    int myNum = 1000;
    float myFloat = 5.75;
    double myDouble = 19.99;
    float scientificFloat = 35e3; // 35,000
    double scientificDouble = 12E4; // 120,000
    cout << "int: " << myNum << endl;
    cout << "float: " << myFloat << endl;
    cout << "double: " << myDouble << endl;
    cout << "Scientific float: " << scientificFloat << endl;
    cout << "Scientific double: " << scientificDouble << endl;
}

// Function to demonstrate character types
void demoCharTypes() {
    // Logic: Use char with literals and ASCII values
    char myGrade = 'B';
    char a = 65; // ASCII for 'A'
    char b = 66; // ASCII for 'B'
    cout << "Char literal: " << myGrade << endl;
    cout << "ASCII char (65): " << a << endl;
    cout << "ASCII char (66): " << b << endl;
}

// Function to demonstrate string types
void demoStringTypes() {
    // Logic: Store and display a string
    string greeting = "Hello";
    cout << "String: " << greeting << endl;
}

// Function to demonstrate boolean types
void demoBooleanTypes() {
    // Logic: Use bool for true/false values
    bool isCodingFun = true;
    bool isFishTasty = false;
    cout << "bool (true): " << isCodingFun << endl;
    cout << "bool (false): " << isFishTasty << endl;
}

// Function to demonstrate auto keyword
void demoAutoKeyword() {
    // Logic: Use auto to deduce types
    auto myNum = 5;          // int
    auto myFloat = 5.99;     // double (literal is double unless 'f')
    auto myLetter = 'D';     // char
    auto myBoolean = true;   // bool
    auto myString = string("Hello"); // string
    cout << "auto int: " << myNum << endl;
    cout << "auto double: " << myFloat << endl;
    cout << "auto char: " << myLetter << endl;
    cout << "auto bool: " << myBoolean << endl;
    cout << "auto string: " << myString << endl;
}

// Function to demonstrate student grade checker
void demoStudentGradeChecker() {
    // Logic: Store student data and check pass/fail
    int studentID = 123;
    double score = 85.5;
    char grade = 'B';
    bool passed = score >= 60;
    cout << "Student ID: " << studentID << endl;
    cout << "Score: " << score << endl;
    cout << "Grade: " << grade << endl;
    cout << "Passed: " << passed << endl;
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ Data Types Demonstration ===" << endl;

    cout << "\n1. Numeric Types:" << endl;
    demoNumericTypes();

    cout << "\n2. Character Types:" << endl;
    demoCharTypes();

    cout << "\n3. String Types:" << endl;
    demoStringTypes();

    cout << "\n4. Boolean Types:" << endl;
    demoBooleanTypes();

    cout << "\n5. Auto Keyword:" << endl;
    demoAutoKeyword();

    cout << "\n6. Student Grade Checker:" << endl;
    demoStudentGradeChecker();

    cout << "\n7. Exercise Answers:" << endl;
    cout << "Q1: Which data type for whole number without decimals? Answer: int" << endl;
    cout << "Q2: Which data type for single character? Answer: char" << endl;
    cout << "Q3: Which data type for sequence of characters? Answer: string" << endl;
    cout << "Q4: Which data type for true/false values? Answer: bool" << endl;

    return 0;
}