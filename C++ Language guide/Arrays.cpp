#include <iostream>
#include <string>
using namespace std;

// Function declarations
void printHeader(const string& title);
void demonstrateArrayCreation();
void demonstrateArrayInitialization();
void demonstrateAccessElements();
void demonstrateUpdateElements();
void demonstrateTraverseArray();
void demonstrateArraySize();
void demonstrateArraysAndPointers();
void demonstratePassArrayToFunction();
void printArray(int[], int);
void demonstrateMultidimensionalArray();
void demonstratePracticeProblems();

// Helper functions for practice problems
int sumArray(int arr[], int n);
int findLargest(int arr[], int n);

int main() {
    printHeader("C++ Arrays Demo");
    demonstrateArrayCreation();
    demonstrateArrayInitialization();
    demonstrateAccessElements();
    demonstrateUpdateElements();
    demonstrateTraverseArray();
    demonstrateArraySize();
    demonstrateArraysAndPointers();
    demonstratePassArrayToFunction();
    demonstrateMultidimensionalArray();
    demonstratePracticeProblems();
    return 0;
}

// Utility to print section headers
void printHeader(const string& title) {
    cout << "\n=== " << title << " ===\n";
}

// 1. Array Creation
void demonstrateArrayCreation() {
    printHeader("Array Creation");
    // Theory: Arrays are declared with a fixed size and data type.

    int arr[5]; // Uninitialized array
    cout << "Array declared with size 5 (uninitialized values)." << endl;

    // Note: Printing uninitialized values may show garbage; skipped for safety.
}

// 2. Array Initialization
void demonstrateArrayInitialization() {
    printHeader("Array Initialization");
    // Theory: Arrays can be initialized with values, partially or fully.

    int arr[5] = {2, 4, 8}; // Partial initialization
    int arr2[] = {2, 4, 8, 12, 16}; // Size inferred
    int arr3[5] = {0}; // All zeros

    cout << "Partial initialization: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " "; // 2 4 8 0 0
    }
    cout << endl;

    cout << "Inferred size: ";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " "; // 2 4 8 12 16
    }
    cout << endl;

    cout << "All zeros: ";
    for (int i = 0; i < 5; i++) {
        cout << arr3[i] << " "; // 0 0 0 0 0
    }
    cout << endl;
}

// 3. Accessing Array Elements
void demonstrateAccessElements() {
    printHeader("Accessing Array Elements");
    // Theory: Elements are accessed using zero-based indices.

    int arr[] = {2, 4, 8, 12, 16};
    cout << "Fourth element: " << arr[3] << endl; // 12
    cout << "First element: " << arr[0] << endl; // 2
}

// 4. Updating Array Elements
void demonstrateUpdateElements() {
    printHeader("Updating Array Elements");
    // Theory: Elements can be modified using index and assignment.

    int arr[] = {2, 4, 8, 12, 16};
    arr[0] = 90; // Update first element
    cout << "Updated first element: " << arr[0] << endl; // 90
}

// 5. Traversing Array
void demonstrateTraverseArray() {
    printHeader("Traversing Array");
    // Theory: Visit each element using a loop.

    int arr[5] = {2, 4, 8, 12, 16};
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 6. Size of Array
void demonstrateArraySize() {
    printHeader("Size of Array");
    // Theory: Calculate size using sizeof(array) / sizeof(array[0]).

    char arr[] = {'a', 'b', 'c', 'd', 'f'};
    cout << "Size of arr[0]: " << sizeof(arr[0]) << " bytes" << endl; // 1
    cout << "Size of arr: " << sizeof(arr) << " bytes" << endl; // 5
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of array: " << n << endl; // 5
}

// 7. Arrays and Pointers
void demonstrateArraysAndPointers() {
    printHeader("Arrays and Pointers");
    // Theory: Array name is a constant pointer to the first element.

    int arr[] = {2, 4, 8, 12, 16};
    int* ptr = arr;
    cout << "Array name address: " << arr << endl;
    cout << "First element address: " << &arr[0] << endl;
    cout << "Elements via pointer: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

// 8. Passing Array to Function
void demonstratePassArrayToFunction() {
    printHeader("Passing Array to Function");
    // Theory: Arrays are passed as pointers; size must be passed separately.

    int arr[] = {2, 4, 8, 12, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array from function: ";
    printArray(arr, n);
    cout << endl;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// 9. Multidimensional Array
void demonstrateMultidimensionalArray() {
    printHeader("Multidimensional Array");
    // Theory: Arrays with multiple dimensions (e.g., 2D for rows/columns).

    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << "2D array elements:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// 10. Practice Problems
void demonstratePracticeProblems() {
    printHeader("Practice Problems");
    // Theory: Common algorithmic problems using arrays.

    int arr[] = {2, 4, 8, 12, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum of elements: " << sumArray(arr, n) << endl;
    cout << "Largest element: " << findLargest(arr, n) << endl;
}

int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int findLargest(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}