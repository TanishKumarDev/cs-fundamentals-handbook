#include <iostream>
using namespace std;

// Function to demonstrate boolean values
void demoBooleanValues() {
    // Logic: Declare and output boolean variables
    bool isCodingFun = true;
    bool isFishTasty = false;
    cout << "isCodingFun: " << isCodingFun << endl; // 1
    cout << "isFishTasty: " << isFishTasty << endl; // 0
}

// Function to demonstrate boolean expressions
void demoBooleanExpressions() {
    // Logic: Evaluate comparisons
    int x = 10, y = 9;
    cout << "x > y: " << (x > y) << endl;       // 1 (true)
    cout << "x == 10: " << (x == 10) << endl;   // 1 (true)
    cout << "10 == 15: " << (10 == 15) << endl; // 0 (false)
}

// Function to demonstrate voting age check
void demoVotingAgeCheck() {
    // Logic: Check voting eligibility
    int myAge = 25;
    int votingAge = 18;
    bool canVote = myAge >= votingAge;
    cout << "Can vote (boolean): " << canVote << endl; // 1
    if (myAge >= votingAge) {
        cout << "Old enough to vote!" << endl;
    } else {
        cout << "Not old enough to vote." << endl;
    }
}

// Function to demonstrate system status checker
void demoSystemStatusChecker() {
    // Logic: Check system status with multiple conditions
    bool isPowerOn = true;
    double temperature = 75.5;
    const double TEMP_LIMIT = 80.0;
    bool isOperational = isPowerOn && (temperature < TEMP_LIMIT);
    cout << "Is operational: " << isOperational << endl; // 1
    if (isOperational) {
        cout << "System is operational." << endl;
    } else {
        cout << "System check failed." << endl;
    }
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ Booleans Demonstration ===" << endl;

    cout << "\n1. Boolean Values:" << endl;
    demoBooleanValues();

    cout << "\n2. Boolean Expressions:" << endl;
    demoBooleanExpressions();

    cout << "\n3. Voting Age Check:" << endl;
    demoVotingAgeCheck();

    cout << "\n4. System Status Checker:" << endl;
    demoSystemStatusChecker();

    cout << "\n5. Exercise Answer:" << endl;
    cout << "Q: Output of 'bool isSunny = false; cout << isSunny;'? Answer: 0" << endl;

    return 0;
}
