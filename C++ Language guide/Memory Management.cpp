#include <iostream>
#include <string>
using namespace std;

// Function to demonstrate automatic memory allocation
void demoAutomaticMemory() {
    // Logic: Declare variables and show automatic allocation
    int myNumber = 10;
    string myString = "Hello";
    cout << "Automatic Memory - int: " << myNumber << endl;
    cout << "Automatic Memory - string: " << myString << endl;
    // Memory is freed when variables go out of scope
}

// Function to demonstrate sizeof operator
void demoSizeOf() {
    // Logic: Check memory sizes of various types
    int myInt;
    float myFloat;
    double myDouble;
    char myChar;
    cout << "Size of int: " << sizeof(myInt) << " bytes" << endl;
    cout << "Size of float: " << sizeof(myFloat) << " bytes" << endl;
    cout << "Size of double: " << sizeof(myDouble) << " bytes" << endl;
    cout << "Size of char: " << sizeof(myChar) << " bytes" << endl;
}

// Function to demonstrate single variable allocation with new/delete
void demoSingleAllocation() {
    // Logic: Allocate and deallocate a single integer
    int* ptr = new int;
    *ptr = 35;
    cout << "Single Allocation - Value: " << *ptr << endl;
    delete ptr;
    ptr = nullptr; // Prevent dangling pointer
    cout << "Memory deallocated" << endl;
}

// Function to demonstrate dynamic array for guest names
void demoGuestNames() {
    // Logic: Simulate hotel guest names with dynamic array
    // Simulate user input for numGuests and names
    int numGuests = 3; // Simulated input
    string simulatedNames[] = {"John", "Liam", "Jenny"}; // Simulated names

    if (numGuests <= 0) {
        cout << "Number of guests must be at least 1." << endl;
        return;
    }

    // Allocate array
    string* guests = new string[numGuests];

    // Populate array with simulated input
    for (int i = 0; i < numGuests; i++) {
        guests[i] = simulatedNames[i];
    }

    // Display guests
    cout << "Guests checked in:" << endl;
    for (int i = 0; i < numGuests; i++) {
        cout << guests[i] << endl;
    }

    // Deallocate
    delete[] guests;
    guests = nullptr;
    cout << "Guest array deallocated" << endl;
}

// Function to demonstrate dynamic score tracker
void demoScoreTracker() {
    // Logic: Track scores in a dynamic array
    // Simulate user input for numScores and scores
    int numScores = 4; // Simulated input
    int simulatedScores[] = {85, 90, 78, 92}; // Simulated scores

    if (numScores <= 0) {
        cout << "Number of scores must be at least 1." << endl;
        return;
    }

    // Allocate array
    int* scores = new int[numScores];

    // Populate array
    for (int i = 0; i < numScores; i++) {
        scores[i] = simulatedScores[i];
    }

    // Calculate average
    double avg = 0;
    for (int i = 0; i < numScores; i++) {
        avg += scores[i];
    }
    avg /= numScores;
    cout << "Score Tracker - Average score: " << avg << endl;

    // Deallocate
    delete[] scores;
    scores = nullptr;
    cout << "Scores array deallocated" << endl;
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ Memory Management Demonstration ===" << endl;

    cout << "\n1. Automatic Memory Allocation:" << endl;
    demoAutomaticMemory();

    cout << "\n2. Checking Memory Size with sizeof:" << endl;
    demoSizeOf();

    cout << "\n3. Single Variable Allocation with new/delete:" << endl;
    demoSingleAllocation();

    cout << "\n4. Dynamic Array for Guest Names:" << endl;
    demoGuestNames();

    cout << "\n5. Dynamic Score Tracker:" << endl;
    demoScoreTracker();

    return 0;
}