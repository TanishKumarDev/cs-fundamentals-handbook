#include <iostream>
#include <string>
using namespace std;

// Function to demonstrate array declaration and initialization
void demoArrayDeclaration() {
    // Logic: Declare and initialize arrays of strings and integers
    string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
    int myNum[3] = {10, 20, 30};
    cout << "First car: " << cars[0] << endl;
    cout << "First number: " << myNum[0] << endl;
}

// Function to demonstrate accessing array elements
void demoAccessElements() {
    // Logic: Access specific elements using indices
    string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
    cout << "Accessing cars[0]: " << cars[0] << endl;
}

// Function to demonstrate changing array elements
void demoChangeElements() {
    // Logic: Modify an element and display the change
    string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
    cars[0] = "Opel";
    cout << "After change, cars[0]: " << cars[0] << endl;
}

// Function to demonstrate for loop with arrays
void demoForLoop() {
    // Logic: Loop through array elements with index
    string cars[5] = {"Volvo", "BMW", "Ford", "Mazda", "Tesla"};
    for (int i = 0; i < 5; i++) {
        cout << i << " = " << cars[i] << endl;
    }
}

// Function to demonstrate for-each loop with arrays
void demoForEachLoop() {
    // Logic: Iterate over array elements using for-each
    int myNumbers[5] = {10, 20, 30, 40, 50};
    cout << "Integers: ";
    for (int i : myNumbers) {
        cout << i << " ";
    }
    cout << endl;

    string cars[5] = {"Volvo", "BMW", "Ford", "Mazda", "Tesla"};
    cout << "Cars: ";
    for (string car : cars) {
        cout << car << " ";
    }
    cout << endl;
}

// Function to demonstrate omitting array size
void demoOmitArraySize() {
    // Logic: Initialize array without specifying size
    string cars[] = {"Volvo", "BMW", "Ford"};
    cout << "Cars (no size specified): ";
    for (string car : cars) {
        cout << car << " ";
    }
    cout << endl;
}

// Function to demonstrate assigning elements later
void demoAssignLater() {
    // Logic: Declare array with size, assign values later
    string cars[5];
    cars[0] = "Volvo";
    cars[1] = "BMW";
    cars[2] = "Ford";
    cars[3] = "Mazda";
    cars[4] = "Tesla";
    cout << "Assigned cars: ";
    for (string car : cars) {
        cout << car << " ";
    }
    cout << endl;
}

// Function to demonstrate array size with sizeof
void demoArraySize() {
    // Logic: Calculate array length using sizeof
    int myNumbers[5] = {10, 20, 30, 40, 50};
    int length = sizeof(myNumbers) / sizeof(myNumbers[0]);
    cout << "Array length: " << length << endl;
    for (int i = 0; i < length; i++) {
        cout << myNumbers[i] << " ";
    }
    cout << endl;
}

// Function to demonstrate average age calculation
void demoAverageAge() {
    // Logic: Calculate average of ages using for-each
    int ages[8] = {20, 22, 18, 35, 48, 26, 87, 70};
    float sum = 0;
    int length = sizeof(ages) / sizeof(ages[0]);
    for (int age : ages) {
        sum += age;
    }
    float avg = sum / length;
    cout << "Average age: " << avg << endl;
}

// Function to demonstrate finding lowest age
void demoLowestAge() {
    // Logic: Find minimum age using for-each
    int ages[8] = {20, 22, 18, 35, 48, 26, 87, 70};
    int lowestAge = ages[0];
    for (int age : ages) {
        if (lowestAge > age) {
            lowestAge = age;
        }
    }
    cout << "Lowest age: " << lowestAge << endl;
}

// Function to demonstrate multi-dimensional array
void demoMultiDimensionalArray() {
    // Logic: Access and modify elements in a 2D array
    string letters[2][4] = {
        {"A", "B", "C", "D"},
        {"E", "F", "G", "H"}
    };
    cout << "Element [0][2]: " << letters[0][2] << endl;
    letters[0][0] = "Z";
    cout << "After change, [0][0]: " << letters[0][0] << endl;
}

// Function to demonstrate looping through 2D array
void demoLoop2DArray() {
    // Logic: Use nested loops to print 2D array elements
    string letters[2][4] = {
        {"A", "B", "C", "D"},
        {"E", "F", "G", "H"}
    };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cout << letters[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to demonstrate looping through 3D array
void demoLoop3DArray() {
    // Logic: Use triple nested loops to print 3D array elements
    string letters[2][2][2] = {
        {{"A", "B"}, {"C", "D"}},
        {{"E", "F"}, {"G", "H"}}
    };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                cout << letters[i][j][k] << " ";
            }
            cout << endl;
        }
    }
}

// Function to demonstrate Battleship game
void demoBattleshipGame() {
    // Logic: Simulate Battleship game with 2D array
    bool ships[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0}
    };
    int hits = 0;
    int numberOfTurns = 0;

    // Simulate one round for demonstration (non-interactive)
    int row = 0, column = 1; // Example coordinates
    if (ships[row][column]) {
        ships[row][column] = 0;
        hits++;
        cout << "Hit! " << (4 - hits) << " left." << endl;
    } else {
        cout << "Miss" << endl;
    }
    numberOfTurns++;
    cout << "Turns taken: " << numberOfTurns << endl;
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ Arrays Demonstration ===" << endl;

    cout << "\n1. Array Declaration and Initialization:" << endl;
    demoArrayDeclaration();

    cout << "\n2. Accessing Array Elements:" << endl;
    demoAccessElements();

    cout << "\n3. Changing Array Elements:" << endl;
    demoChangeElements();

    cout << "\n4. For Loop with Arrays:" << endl;
    demoForLoop();

    cout << "\n5. For-Each Loop with Arrays:" << endl;
    demoForEachLoop();

    cout << "\n6. Omitting Array Size:" << endl;
    demoOmitArraySize();

    cout << "\n7. Assigning Elements Later:" << endl;
    demoAssignLater();

    cout << "\n8. Array Size with sizeof:" << endl;
    demoArraySize();

    cout << "\n9. Average Age Calculation:" << endl;
    demoAverageAge();

    cout << "\n10. Finding Lowest Age:" << endl;
    demoLowestAge();

    cout << "\n11. Multi-Dimensional Array:" << endl;
    demoMultiDimensionalArray();

    cout << "\n12. Looping Through 2D Array:" << endl;
    demoLoop2DArray();

    cout << "\n13. Looping Through 3D Array:" << endl;
    demoLoop3DArray();

    cout << "\n14. Battleship Game (One Round):" << endl;
    demoBattleshipGame();

    return 0;
}