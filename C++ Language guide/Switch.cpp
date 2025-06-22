#include <iostream>
using namespace std;

// Function to demonstrate basic switch for weekday name
void demoWeekdayName() {
    // Logic: Map day number to name
    int day = 4;
    cout << "Day " << day << ": ";
    switch (day) {
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        case 7:
            cout << "Sunday";
            break;
    }
    cout << endl;
}

// Function to demonstrate break and fall-through
void demoBreakKeyword() {
    // Logic: Show break and intentional fall-through
    int day = 3;
    cout << "Day " << day << ": ";
    switch (day) {
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            // Fall-through
        case 3:
            cout << "Wednesday or Tuesday";
            break;
        case 4:
            cout << "Thursday";
            break;
    }
    cout << endl;
}

// Function to demonstrate default keyword
void demoDefaultKeyword() {
    // Logic: Handle unmatched cases
    int day = 4;
    cout << "Day " << day << ": ";
    switch (day) {
        case 6:
            cout << "Today is Saturday";
            break;
        case 7:
            cout << "Today is Sunday";
            break;
        default:
            cout << "Looking forward to the Weekend";
    }
    cout << endl;
}

// Function to demonstrate grade classifier
void demoGradeClassifier() {
    // Logic: Map letter grade to description
    char grade = 'B';
    cout << "Grade " << grade << ": ";
    switch (grade) {
        case 'A':
            cout << "Excellent";
            break;
        case 'B':
            cout << "Good";
            break;
        case 'C':
            cout << "Average";
            break;
        default:
            cout << "Invalid grade";
    }
    cout << endl;
}

// Function to demonstrate menu system
void demoMenuSystem() {
    // Logic: Simulate menu selection
    int choice = 2;
    cout << "Menu choice " << choice << ": ";
    switch (choice) {
        case 1:
            cout << "Start game";
            break;
        case 2:
            cout << "Load game";
            break;
        case 3:
            cout << "Exit";
            break;
        default:
            cout << "Invalid choice";
    }
    cout << endl;
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ Switch Statements Demonstration ===" << endl;

    cout << "\n1. Weekday Name:" << endl;
    demoWeekdayName();

    cout << "\n2. Break Keyword (with Fall-through):" << endl;
    demoBreakKeyword();

    cout << "\n3. Default Keyword:" << endl;
    demoDefaultKeyword();

    cout << "\n4. Grade Classifier:" << endl;
    demoGradeClassifier();

    cout << "\n5. Menu System:" << endl;
    demoMenuSystem();

    return 0;
}
