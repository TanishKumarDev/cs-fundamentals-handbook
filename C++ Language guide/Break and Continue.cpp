#include <iostream>
using namespace std;

// Function to demonstrate break in for loop
void demoBreakFor() {
    // Logic: Print numbers 0 to 9, stop when i == 4
    for (int i = 0; i < 10; i++) {
        if (i == 4) {
            break; // Exit loop when i is 4
        }
        cout << i << endl;
    }
}

// Function to demonstrate continue in for loop
void demoContinueFor() {
    // Logic: Print numbers 0 to 9, skip i == 4
    for (int i = 0; i < 10; i++) {
        if (i == 4) {
            continue; // Skip iteration when i is 4
        }
        cout << i << endl;
    }
}

// Function to demonstrate break in while loop
void demoBreakWhile() {
    // Logic: Print numbers 0 to 9, stop when i == 4
    int i = 0;
    while (i < 10) {
        cout << i << endl;
        i++;
        if (i == 4) {
            break; // Exit loop when i is 4
        }
    }
}

// Function to demonstrate continue in while loop
void demoContinueWhile() {
    // Logic: Print numbers 0 to 9, skip i == 4
    int i = 0;
    while (i < 10) {
        if (i == 4) {
            i++; // Update i before continue to avoid infinite loop
            continue; // Skip iteration when i is 4
        }
        cout << i << endl;
        i++;
    }
}

// Function to demonstrate searching with break
void demoSearchBreak() {
    // Logic: Search for target number and stop when found
    int target = 7;
    for (int i = 0; i < 10; i++) {
        if (i == target) {
            cout << "Found " << target << " at index " << i << endl;
            break; // Exit loop when target is found
        }
    }
}

// Function to demonstrate skipping odd numbers with continue
void demoSkipOddNumbers() {
    // Logic: Print only even numbers by skipping odd ones
    for (int i = 0; i < 10; i++) {
        if (i % 2 != 0) {
            continue; // Skip odd numbers
        }
        cout << i << endl;
    }
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ Break and Continue Demonstration ===" << endl;

    cout << "\n1. Break in For Loop:" << endl;
    demoBreakFor();

    cout << "\n2. Continue in For Loop:" << endl;
    demoContinueFor();

    cout << "\n3. Break in While Loop:" << endl;
    demoBreakWhile();

    cout << "\n4. Continue in While Loop:" << endl;
    demoContinueWhile();

    cout << "\n5. Search with Break:" << endl;
    demoSearchBreak();

    cout << "\n6. Skip Odd Numbers with Continue:" << endl;
    demoSkipOddNumbers();

    return 0;
}