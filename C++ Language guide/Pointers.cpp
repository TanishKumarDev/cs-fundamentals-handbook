#include <iostream>
using namespace std;

int main() {
    // ----------------------------------------------------
    // 1. INTRODUCTION TO POINTERS
    // ----------------------------------------------------
    int a = 10;
    int* p = &a;  // 'p' is a pointer storing address of 'a'

    cout << "Value of a: " << a << endl;
    cout << "Address of a (&a): " << &a << endl;
    cout << "Pointer p (holds address of a): " << p << endl;
    cout << "Value pointed by p (*p): " << *p << endl << endl;

    // ----------------------------------------------------
    // 2. APPLICATIONS OF POINTERS
    // ----------------------------------------------------
    *p = 20;  // Modifying 'a' using pointer
    cout << "Modified value of a via pointer: " << a << endl;

    // Pointers are used for:
    // - Access/modification via address
    // - Passing variables to functions by address (call by reference)
    // - Dynamic memory allocation
    // - Building data structures like linked lists, trees

    // ----------------------------------------------------
    // 3. POINTER ARITHMETIC
    // ----------------------------------------------------
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;  // same as &arr[0]

    cout << "\nPointer Arithmetic on Array:\n";
    cout << "*ptr (arr[0]) = " << *ptr << endl;
    cout << "*(ptr + 1) = " << *(ptr + 1) << endl;
    cout << "*(ptr + 2) = " << *(ptr + 2) << endl;

    ptr++;  // moves to next int (arr[1])
    cout << "After ptr++, *ptr = " << *ptr << endl;

    // ----------------------------------------------------
    // 4. TYPES OF SPECIAL POINTERS
    // ----------------------------------------------------

    // NULL POINTER → pointer pointing to nothing
    int* nullPtr = nullptr;
    cout << "\nNull Pointer = " << nullPtr << endl;

    // VOID POINTER → generic pointer (can point to any type)
    void* voidPtr;
    int x = 100;
    voidPtr = &x;
    cout << "Void Pointer (can't dereference directly) = " << voidPtr << endl;
    // Need type casting to use it: *((int*)voidPtr)

    // DANGLING POINTER → points to memory that no longer exists
    int* danglingPtr;
    {
        int temp = 55;
        danglingPtr = &temp;
    } // temp is destroyed here; danglingPtr becomes unsafe
    // Don't use *danglingPtr now → unsafe

    // WILD POINTER → uninitialized pointer (points nowhere valid)
    int* wildPtr;  // contains garbage address
    // *wildPtr; // Undefined behavior (never do this)

    // ----------------------------------------------------
    // 5. REFERENCES (ALIAS)
    // ----------------------------------------------------
    int y = 50;
    int& ref = y;  // reference (ref) is another name for y

    ref = 60;  // this changes y
    cout << "\nReference ref = " << ref << ", y = " << y << endl;

    // Reference rules:
    // - Must be initialized when declared
    // - Can't be NULL
    // - Safer than pointers

    // ----------------------------------------------------
    // 6. POINTERS vs REFERENCES
    // ----------------------------------------------------
    cout << "\nPOINTER vs REFERENCE:\n";
    cout << "Pointer (*p): Value = " << *p << ", Address = " << p << endl;
    cout << "Reference (&ref): Value = " << ref << ", Address = " << &ref << endl;

    // Summary:

    // Pointers:
    // - Can be reassigned to other addresses
    // - Can be NULL
    // - Need dereferencing (*)
    // - Can do pointer arithmetic

    // References:
    // - Alias (alternate name)
    // - Must be initialized once
    // - Can't be NULL
    // - No pointer arithmetic

    return 0;
}
