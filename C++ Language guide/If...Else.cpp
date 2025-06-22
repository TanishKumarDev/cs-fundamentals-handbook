#include <iostream>
#include <string>
using namespace std;

// Function to demonstrate basic if statement
void demoBasicIf() {
    // Logic: Check if 20 is greater than 18
    if (20 > 18) {
        cout << "20 is greater than 18" << endl;
    }

    // Logic: Compare two variables
    int x = 20, y = 18;
    if (x > y) {
        cout << "x is greater than y" << endl;
    }
}

// Function to demonstrate if-else statement
void demoIfElse() {
    // Logic: Check time to print greeting
    int time = 20;
    if (time < 18) {
        cout << "Good day." << endl;
    } else {
        cout << "Good evening." << endl;
    }
}

// Function to demonstrate else-if statement
void demoElseIf() {
    // Logic: Check time to print appropriate greeting
    int time = 22;
    if (time < 10) {
        cout << "Good morning." << endl;
    } else if (time < 20) {
        cout << "Good day." << endl;
    } else {
        cout << "Good evening." << endl;
    }
}

// Function to demonstrate ternary operator
void demoTernary() {
    // Logic: Use ternary operator for concise if-else
    int time = 20;
    string result = (time < 18) ? "Good day." : "Good evening.";
    cout << "Ternary result: " << result << endl;
}

// Function to demonstrate door code validation
void demoDoorCode() {
    // Logic: Validate door code
    int doorCode = 1337;
    if (doorCode == 1337) {
        cout << "Correct code.\nThe door is now open.\n";
    } else {
        cout << "Wrong code.\nThe door remains closed.\n";
    }
}

// Function to demonstrate positive/negative number check
void demoNumberSign() {
    // Logic: Check if number is positive, negative, or zero
    int myNum = 10;
    if (myNum > 0) {
        cout << "The value is a positive number.\n";
    } else if (myNum < 0) {
        cout << "The value is a negative number.\n";
    } else {
        cout << "The value is 0.\n";
    }
}

// Function to demonstrate voting age check
void demoVotingAge() {
    // Logic: Check if age is sufficient for voting
    int myAge = 25;
    int votingAge = 18;
    if (myAge >= votingAge) {
        cout << "Old enough to vote!\n";
    } else {
        cout << "Not old enough to vote.\n";
    }
}

// Function to demonstrate even/odd number check
void demoEvenOdd() {
    // Logic: Check if number is even or odd using modulo
    int myNum = 5;
    if (myNum % 2 == 0) {
        cout << myNum << " is even.\n";
    } else {
        cout << myNum << " is odd.\n";
    }
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ If-Else Demonstration ===" << endl;

    // Call each function to demonstrate concepts
    cout << "\n1. Basic If Statement:" << endl;
    demoBasicIf();

    cout << "\n2. If-Else Statement:" << endl;
    demoIfElse();

    cout << "\n3. Else-If Statement:" << endl;
    demoElseIf();

    cout << "\n4. Ternary Operator:" << endl;
    demoTernary();

    cout << "\n5. Door Code Validation:" << endl;
    demoDoorCode();

    cout << "\n6. Positive/Negative Number Check:" << endl;
    demoNumberSign();

    cout << "\n7. Voting Age Check:" << endl;
    demoVotingAge();

    cout << "\n8. Even/Odd Number Check:" << endl;
    demoEvenOdd();

    return 0;
}cpp