#include <iostream>
#include <string>

/**
 * Demonstrates various flow control structures in C++:
 * - If statement
 * - If-Else statement
 * - Else-If ladder
 * - Ternary operator
 * - Switch statement
 * - While loop
 * - Do-While loop
 * - For loop
 * - Nested loops
 * - Range-based for loop (foreach)
 * - Break and continue statements
 * 
 * Each section prints output to illustrate how the control structure works.
 */
int main() {
    // Section 1: If Statement
    // Executes the block if the condition is true
    std::cout << "Section 1: If Statement" << std::endl;
    if (20 > 18) {
        std::cout << "20 is greater than 18" << std::endl;
    }

    // Section 2: If-Else Statement
    // Executes one block if condition is true, else executes another block
    std::cout << "\nSection 2: If-Else Statement" << std::endl;
    int time = 20;
    if (time < 18) {
        std::cout << "Good day." << std::endl;
    } else {
        std::cout << "Good evening." << std::endl;
    }

    // Section 3: Else-If Statement
    // Checks multiple conditions sequentially
    std::cout << "\nSection 3: Else-If Statement" << std::endl;
    time = 22;
    if (time < 10) {
        std::cout << "Good morning." << std::endl;
    } else if (time < 20) {
        std::cout << "Good day." << std::endl;
    } else {
        std::cout << "Good evening." << std::endl;
    }

    // Section 4: Ternary Operator
    // A compact form of if-else that returns a value based on a condition
    std::cout << "\nSection 4: Ternary Operator" << std::endl;
    std::string result = (time < 18) ? "Good day." : "Good evening.";
    std::cout << result << std::endl;

    // Section 5: Switch Statement
    // Selects a block to execute based on the value of a variable
    std::cout << "\nSection 5: Switch Statement" << std::endl;
    int day = 4;
    switch (day) {
        case 1: std::cout << "Monday" << std::endl; break;
        case 2: std::cout << "Tuesday" << std::endl; break;
        case 3: std::cout << "Wednesday" << std::endl; break;
        case 4: std::cout << "Thursday" << std::endl; break;
        case 5: std::cout << "Friday" << std::endl; break;
        case 6: std::cout << "Saturday" << std::endl; break;
        case 7: std::cout << "Sunday" << std::endl; break;
        default: std::cout << "Invalid day" << std::endl;
    }

    // Section 6: While Loop
    // Repeats a block while a condition is true
    std::cout << "\nSection 6: While Loop" << std::endl;
    int i = 0;
    while (i < 3) {
        std::cout << i << std::endl;
        i++;
    }

    // Section 7: Do-While Loop
    // Executes the block at least once, then repeats while condition is true
    std::cout << "\nSection 7: Do-While Loop" << std::endl;
    i = 0;
    do {
        std::cout << i << std::endl;
        i++;
    } while (i < 3);

    // Section 8: For Loop
    // Repeats a block a fixed number of times
    std::cout << "\nSection 8: For Loop" << std::endl;
    for (int j = 0; j < 3; j++) {
        std::cout << j << std::endl;
    }

    // Section 9: Nested Loops
    // Loop inside another loop, useful for multi-dimensional iteration
    std::cout << "\nSection 9: Nested Loops" << std::endl;
    for (int k = 1; k <= 2; k++) {
        std::cout << "Outer: " << k << std::endl;
        for (int m = 1; m <= 2; m++) {
            std::cout << " Inner: " << m << std::endl;
        }
    }

    // Section 10: Foreach Loop (Range-based for loop)
    // Iterates over elements in a container or array
    std::cout << "\nSection 10: Foreach Loop" << std::endl;
    int numbers[3] = {10, 20, 30};
    for (int num : numbers) {
        std::cout << num << std::endl;
    }

    // Section 11: Break and Continue
    // Break exits the loop immediately
    // Continue skips the current iteration and proceeds to the next
    std::cout << "\nSection 11: Break and Continue" << std::endl;

    // Break example
    for (int n = 0; n < 5; n++) {
        if (n == 3) {
            break; // Exit loop when n == 3
        }
        std::cout << "Break example: " << n << std::endl;
    }

    // Continue example
    for (int n = 0; n < 5; n++) {
        if (n == 3) {
            continue; // Skip printing when n == 3
        }
        std::cout << "Continue example: " << n << std::endl;
    }

    return 0; // Successful termination
}