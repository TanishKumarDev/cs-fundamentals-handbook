// File: input_example.cpp

#include <iostream>
#include <string> // Required for using std::string and getline()

using namespace std;

int main() {
    // Declare variables
    int age;
    string fullName;

    // Ask for age first
    cout << "Enter your age: ";
    cin >> age;

    // ❗ Important: Use cin.ignore() to clean the newline left in input buffer
    cin.ignore();  // It removes the leftover '\n' after entering age
    

    // Now take full name with spaces
    cout << "Enter your full name: ";
    getline(cin, fullName);  // This reads the entire line

    // Print output
    cout << "\n--- Summary ---\n";
    cout << "Name: " << fullName << "\n";
    cout << "Age: " << age << endl;

    return 0;
}
