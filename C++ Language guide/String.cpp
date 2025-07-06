#include <iostream>
#include <string>
using namespace std;

// Function to demonstrate string creation
void demoStringCreation() {
    // Logic: Create and display a string
    string greeting = "Hello";
    cout << "String: " << greeting << endl;
}

// Function to demonstrate string concatenation
void demoConcatenation() {
    // Logic: Concatenate strings using + and append()
    string firstName = "John";
    string lastName = "Doe";
    string fullName = firstName + " " + lastName;
    cout << "Concatenation (+): " << fullName << endl;

    // Logic: Concatenate strings using append() : appe
    string fullName2 = firstName.append(lastName);
    cout << "Concatenation (append): " << fullName2 << endl;
}

// Function to demonstrate numbers and strings
void demoNumbersAndStrings() {
    // Logic: Concatenate string and number
    int x = 10;
    string y = "20";
    string z = y + to_string(x);
    cout << "String + Number: " << z << endl;
}

// Function to demonstrate string length
void demoStringLength() {
    // Logic: Get string length using length() and size()
    string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "Length: " << txt.length() << endl;
    cout << "Size: " << txt.size() << endl;
}

// Function to demonstrate accessing strings
void demoAccessStrings() {
    // Logic: Access and modify characters using [] and at()
    string myString = "Hello";
    cout << "First char ([]): " << myString[0] << endl;
    cout << "Second char (at): " << myString.at(1) << endl;
    cout << "Last char: " << myString[myString.length() - 1] << endl;
    myString[0] = 'J';
    cout << "Modified string: " << myString << endl;
}

// Function to demonstrate special characters
void demoSpecialCharacters() {
    // Logic: Use escape sequences
    string txt = "We are \"Vikings\" from the north.\nIt\'s \\ cool.";
    cout << "Special characters:\n" << txt << endl;
}

// Function to demonstrate user input
void demoUserInput() {
    // Logic: Simulate user input with getline()
    string fullName = "John Doe"; // Simulated input
    cout << "Simulated full name: " << fullName << endl;
}

// Function to demonstrate namespace omission
void demoNamespace() {
    // Logic: Use std:: explicitly
    std::string greeting = "Hello";
    std::cout << "String without namespace: " << greeting << endl;
}

// Function to demonstrate C-style strings
void demoCStyleStrings() {
    // Logic: Compare C-style and C++ strings
    char greeting2[] = "Hello"; // C-style
    string greeting1 = "Hello"; // C++ string
    cout << "C-style string: " << greeting2 << endl;
    cout << "C++ string: " << greeting1 << endl;
}

// Function to demonstrate user profile formatter
void demoUserProfileFormatter() {
    // Logic: Format a user profile
    string firstName = "John"; // Simulated input
    string lastName = "Doe";
    int age = 30;
    string profile = firstName + " " + lastName + ", Age: " + to_string(age);
    if (profile.length() > 5) {
        cout << "Profile: \"" << profile << "\"" << endl;
    }
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ Strings Demonstration ===" << endl;

    cout << "\n1. String Creation:" << endl;
    demoStringCreation();

    cout << "\n2. String Concatenation:" << endl;
    demoConcatenation();

    cout << "\n3. Numbers and Strings:" << endl;
    demoNumbersAndStrings();

    cout << "\n4. String Length:" << endl;
    demoStringLength();

    cout << "\n5. Accessing Strings:" << endl;
    demoAccessStrings();

    cout << "\n6. Special Characters:" << endl;
    demoSpecialCharacters();

    cout << "\n7. User Input (Simulated):" << endl;
    demoUserInput();

    cout << "\n8. Namespace Omission:" << endl;
    demoNamespace();

    cout << "\n9. C-Style Strings:" << endl;
    demoCStyleStrings();

    cout << "\n10. User Profile Formatter:" << endl;
    demoUserProfileFormatter();

    cout << "\n11. Exercise Answers:" << endl;
    cout << "Q1: Function for string length? Answer: length()" << endl;
    cout << "Q2: Escape for double quotes? Answer: \"" << endl;
    cout << "Q3: Print without namespace? Answer: std::cout << \"Hello\";" << endl;
    cout << "Q4: C-style strings created with? Answer: char arrays" << endl;
    return 0;
}
