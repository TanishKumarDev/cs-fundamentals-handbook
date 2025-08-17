#include <iostream>
#include <memory> // For smart pointers
using namespace std;

// Function declarations for modularity
void demonstrateBasicPointers();
void demonstrateModifyAddress();
void demonstratePointerSize();
void demonstrateWildPointer();
void demonstrateNullPointer();
void demonstrateSmartPointer();
void demonstrateVoidPointer();
void demonstrateDanglingPointer();
void demonstratePointerArithmetic();
void demonstrateDoublePointer();
void demonstrateFunctionPointer();
void printHeader(const string& title);

// Helper function for dangling pointer example
int* getDanglingPointer() {
    int x = 10;
    return &x; // Warning: Returns address of local variable
}

// Function pointer example
void sayHello() {
    cout << "Hello from function pointer!" << endl;
}

int main() {
    // Call each function to demonstrate pointer concepts
    demonstrateBasicPointers();
    demonstrateModifyAddress();
    demonstratePointerSize();
    demonstrateWildPointer();
    demonstrateNullPointer();
    demonstrateSmartPointer();
    demonstrateVoidPointer();
    demonstrateDanglingPointer();
    demonstratePointerArithmetic();
    demonstrateDoublePointer();
    demonstrateFunctionPointer();
    return 0;
}

// Utility to print section headers
void printHeader(const string& title) {
    cout << "\n=== " << title << " ===\n";
}

// 1. Basic Pointers
void demonstrateBasicPointers() {
    printHeader("Basic Pointers");
    // Theory: A pointer stores the memory address of another variable.
    // Dereferencing (*ptr) accesses the value at that address.
    
    int var = 10;
    int* ptr = &var; // Store address of var

    cout << "Value of var: " << var << endl;
    cout << "Address of var: " << &var << endl;
    cout << "Value stored in ptr: " << ptr << endl;
    cout << "Value at ptr (dereferenced): " << *ptr << endl;

    // Example: Modify value via pointer
    *ptr = 15;
    cout << "Modified value of var via ptr: " << var << endl;

    // Output:
    // Value of var: 10
    // Address of var: <some_address>
    // Value stored in ptr: <some_address>
    // Value at ptr (dereferenced): 10
    // Modified value of var via ptr: 15
}

// 2. Modifying Pointer Address
void demonstrateModifyAddress() {
    printHeader("Modifying Pointer Address");
    // Theory: Pointers can be reassigned to point to another variable of the same type.

    int var2 = 20;
    int var3 = 30;
    int* ptr = &var2; // Initially points to var2

    cout << "Value at ptr (points to var2): " << *ptr << endl; // 20
    ptr = &var3; // Reassign to var3
    cout << "Value at ptr (now points to var3): " << *ptr << endl; // 30

    // Output:
    // Value at ptr (points to var2): 20
    // Value at ptr (now points to var3): 30
}

// 3. Size of Pointers
void demonstratePointerSize() {
    printHeader("Size of Pointers");
    // Theory: Pointer size depends on CPU architecture (8 bytes for 64-bit, 4 bytes for 32-bit),
    // not the data type it points to.

    int* ptr1;
    char* ptr2;
    double* ptr3;

    cout << "Size of int pointer: " << sizeof(ptr1) << " bytes" << endl;
    cout << "Size of char pointer: " << sizeof(ptr2) << " bytes" << endl;
    cout << "Size of double pointer: " << sizeof(ptr3) << " bytes" << endl;

    // Output (on 64-bit system):
    // Size of int pointer: 8 bytes
    // Size of char pointer: 8 bytes
    // Size of double pointer: 8 bytes
}

// 4. Wild Pointer
void demonstrateWildPointer() {
    printHeader("Wild Pointer");
    // Theory: A wild pointer is uninitialized and contains a random address.
    // Dereferencing it causes undefined behavior.

    int* wildPtr; // Uninitialized (wild) pointer
    // cout << *wildPtr; // Dangerous: Undefined behavior
    cout << "Wild pointer created (not dereferenced to avoid crash)." << endl;

    // Output:
    // Wild pointer created (not dereferenced to avoid crash).
}

// 5. Null Pointer
void demonstrateNullPointer() {
    printHeader("Null Pointer");
    // Theory: A null pointer is explicitly set to nullptr, indicating it points to no valid memory.
    // Safe to check before dereferencing.

    int* nullPtr = nullptr;
    cout << "Null pointer created: " << nullPtr << endl;
    // if (nullPtr) cout << *nullPtr; // Safe check; won't execute
    cout << "Null pointer not dereferenced to avoid error." << endl;

    // Output:
    // Null pointer created: 0
    // Null pointer not dereferenced to avoid error.
}

// 6. Smart Pointer
void demonstrateSmartPointer() {
    printHeader("Smart Pointer");
    // Theory: Smart pointers (e.g., unique_ptr, shared_ptr) manage memory automatically,
    // preventing leaks. Part of <memory> library.

    unique_ptr<int> smartPtr = make_unique<int>(10);
    cout << "Value at smartPtr: " << *smartPtr << endl;
    // Memory is automatically freed when smartPtr goes out of scope

    // Example with shared_ptr
    shared_ptr<int> sharedPtr = make_shared<int>(20);
    cout << "Value at sharedPtr: " << *sharedPtr << endl;

    // Output:
    // Value at smartPtr: 10
    // Value at sharedPtr: 20
}

// 7. Void Pointer
void demonstrateVoidPointer() {
    printHeader("Void Pointer");
    // Theory: A void pointer can point to any data type but cannot be dereferenced directly.
    // Must be cast to the correct type.

    int x = 10;
    void* voidPtr = &x; // Void pointer to int
    cout << "Value at voidPtr (after casting): " << *(static_cast<int*>(voidPtr)) << endl;

    // Output:
    // Value at voidPtr (after casting): 10
}

// 8. Dangling Pointer
void demonstrateDanglingPointer() {
    printHeader("Dangling Pointer");
    // Theory: A dangling pointer points to memory that is no longer valid (e.g., freed or out of scope).
    // Dereferencing causes undefined behavior.

    int* ptr = getDanglingPointer();
    cout << "Dangling pointer created (not dereferenced to avoid undefined behavior)." << endl;
    // cout << *ptr; // Dangerous: Undefined behavior

    // Example with dynamic memory
    int* dynamicPtr = new int(50);
    delete dynamicPtr;
    cout << "Dynamic pointer deleted (now dangling, not dereferenced)." << endl;
    dynamicPtr = nullptr; // Prevent dangling pointer

    // Output:
    // Dangling pointer created (not dereferenced to avoid undefined behavior).
    // Dynamic pointer deleted (now dangling, not dereferenced).
}

// 9. Pointer Arithmetic
void demonstratePointerArithmetic() {
    printHeader("Pointer Arithmetic");
    // Theory: Pointers can be incremented/decremented or offset by integers to navigate memory,
    // especially in arrays. Steps are sized by the data type.

    int arr[] = {10, 20, 30};
    int* ptr = arr;

    cout << "First element: " << *ptr << endl; // 10
    ptr++; // Move to next element (sizeof(int) bytes)
    cout << "Second element: " << *ptr << endl; // 20
    ptr += 1; // Move to third element
    cout << "Third element: " << *ptr << endl; // 30

    // Pointer subtraction
    int* ptr2 = &arr[2];
    cout << "Distance between ptr2 and ptr: " << ptr2 - ptr << " elements" << endl;

    // Output:
    // First element: 10
    // Second element: 20
    // Third element: 30
    // Distance between ptr2 and ptr: 1 elements
}

// 10. Double Pointer (Pointer to Pointer)
void demonstrateDoublePointer() {
    printHeader("Double Pointer");
    // Theory: A double pointer points to another pointer, useful for multi-level data structures.

    int var = 10;
    int* ptr1 = &var;
    int** ptr2 = &ptr1;

    cout << "Value via ptr1: " << *ptr1 << endl; // 10
    cout << "Value via ptr2: " << **ptr2 << endl; // 10

    // Output:
    // Value via ptr1: 10
    // Value via ptr2: 10
}

// 11. Function Pointer
void demonstrateFunctionPointer() {
    printHeader("Function Pointer");
    // Theory: A function pointer stores the address of a function, enabling indirect calls.

    void (*funcPtr)() = sayHello; // Point to sayHello function
    funcPtr(); // Call function via pointer

    // Output:
    // Hello from function pointer!
}