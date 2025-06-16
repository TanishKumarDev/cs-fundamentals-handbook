 #include <bits/stdc++.h>
using namespace std;

/**
 * Main function: Entry point of the program
 * 
 * This program demonstrates fundamental C++ concepts including:
 * - Basic output using std::cout
 * - Variables and constants declaration and usage
 * - Multiple variable declarations in one line
 * - Different data types (int, double, char, string, bool)
 * - Type inference with the auto keyword
 * - User input with std::cin
 * - String operations such as concatenation and modification
 * - Basic math functions like max and sqrt
 * - Boolean expressions and comparisons
 * 
 * Each section is clearly labeled and outputs relevant information to the console.
 */
int main() {
    // Section 1: Basic Output
    // Demonstrates printing text to the console using std::cout
    std::cout << "Section 1: Basic Output" << std::endl;  // Print section header
    std::cout << "Hello World!" << std::endl;             // Print greeting message
    std::cout << "I am learning C++" << "\n\n";           // Print learning message with double newline

    // Section 2: Variables and Constants
    // Shows how to declare constants and variables, and update variable values
    const int minutesPerHour = 60; // Define a constant for minutes in an hour
    int myNum = 15;                // Declare an integer variable
    std::cout << "Section 2: Variables" << std::endl;     // Print section header
    std::cout << "Minutes per hour: " << minutesPerHour << std::endl; // Output constant value
    std::cout << "myNum: " << myNum << std::endl;         // Output initial variable value
    myNum = 10;                    // Update variable value
    std::cout << "Updated myNum: " << myNum << "\n\n";    // Output updated variable value

    // Section 3: Multiple Variables
    // Demonstrates declaring multiple variables in a single statement and using them
    int x = 5, y = 6, z = 50;      // Declare multiple integer variables
    std::cout << "Section 3: Multiple Variables" << std::endl; // Print section header
    std::cout << "Sum of x + y + z: " << (x + y + z) << "\n\n"; // Output sum of variables

    // Section 4: Data Types
    // Introduces different fundamental data types and how to output them
    double myDouble = 19.99;        // Declare a double variable for floating-point numbers
    char myLetter = 'A';            // Declare a char variable for single characters
    std::string myText = "Hello";   // Declare a string variable for text
    bool isFun = true;              // Declare a boolean variable representing true/false
    std::cout << "Section 4: Data Types" << std::endl; // Print section header
    std::cout << "Double: " << myDouble << ", Char: " << myLetter 
              << ", String: " << myText << ", Bool: " << isFun << "\n\n"; // Output all variables

    // Section 5: Auto Keyword
    // Demonstrates automatic type deduction using the auto keyword
    auto autoNum = 42;              // Compiler infers the type as int
    std::cout << "Section 5: Auto" << std::endl;       // Print section header
    std::cout << "Auto variable: " << autoNum << "\n\n"; // Output auto variable

    // Section 6: User Input
    // Shows how to take input from the user using std::cin
    int userNum;                   // Declare an integer variable for user input
    std::cout << "Section 6: User Input" << std::endl;  // Print section header
    std::cout << "Enter a number: ";                    // Prompt user for input
    std::cin >> userNum;                                 // Read user input from console
    std::cout << "You entered: " << userNum << "\n\n";  // Output user input

    // Section 7: String Operations
    // Demonstrates string concatenation, length retrieval, and character modification
    std::string firstName = "John";                      // Declare first name string
    std::string lastName = "Doe";                        // Declare last name string
    std::string fullName = firstName + " " + lastName;  // Concatenate full name with space
    std::cout << "Section 7: Strings" << std::endl;     // Print section header
    std::cout << "Full name: " << fullName << std::endl; // Output full name
    std::cout << "Length of firstName: " << firstName.length() << std::endl; // Output length of firstName
    firstName[0] = 'J';                                  // Modify first character of firstName
    std::cout << "Modified firstName: " << firstName << "\n\n"; // Output modified firstName

    // Section 8: Math Operations
    // Uses standard math functions like max and sqrt from <cmath>
    std::cout << "Section 8: Math" << std::endl;        // Print section header
    std::cout << "Max of 5 and 10: " << std::max(5, 10) << std::endl; // Output max value
    std::cout << "Square root of 64: " << std::sqrt(64) << std::endl; // Output square root

    // Section 9: Boolean Expressions
    // Demonstrates boolean expressions and how they evaluate to true or false
    int age = 25;                                         // Declare age variable
    std::cout << "Section 9: Booleans" << std::endl;     // Print section header
    std::cout << "Can vote (age >= 18)? " << (age >= 18) << "\n\n"; // Output boolean expression result

    return 0; // Successful termination
}