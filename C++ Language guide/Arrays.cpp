#include <bits/stdc++.h>
using namespace std;

void emptyArray() {
    // Initialize all values to 0
    int emptyArray[10] = {0};

    cout << "Initial array values:\n";
    for (int i = 0; i < 10; i++) { // traverse the array
        cout << emptyArray[i] << " ";
    }
    cout << endl;

    // Now assign new values manually
    /*
    emptyArray[10] = { ... };

    ❗ Problem 1: emptyArray[10] is just one element (out-of-bounds!)
emptyArray[10] accesses index 10, which does not exist (valid range is 0 to 9).

So it’s undefined behavior — memory corruption, crash, or garbage.

❗ Problem 2: C++ does not allow assigning to arrays like that after declaration.
cpp
Copy code
int arr[10] = {1, 2, 3}; // ✅ Allowed only at the time of declaration
After that, you must assign element-by-element.
*/
    emptyArray[0] = 100;
    emptyArray[1] = 20;
    emptyArray[2] = 30;
    emptyArray[3] = 40;
    emptyArray[4] = 50;
    emptyArray[5] = 60;
    emptyArray[6] = 70;
    emptyArray[7] = 80;
    emptyArray[8] = 90;
    emptyArray[9] = 100;

    cout << "Modified array values:\n";
    for (int i = 0; i < 10; i++) { // traverse the array
        cout << emptyArray[i] << " ";
    }
    cout << endl;
}

void sizeofarray() {
     char arr[] = {'a', 'b', 'c', 'd', 'f'};
     cout<<"size of arr[0] = "<<sizeof(arr[0])<<endl;
     cout<<"size of arr = "<<sizeof(arr)<<endl;

    //  length of an array 
    int n = sizeof(arr)/sizeof(arr[0]); // total length/size of each element
    cout<<"length of an array = "<<n<<endl;
    
}
void pointerArray() {
    int arr[5] = {1, 2, 3, 4, 5};

    // print arr name
    cout << "arr = " << arr << endl;

    // print array using pointer
    cout << "arr[0] = " << *(arr) << endl;
    cout << "arr[1] = " << *(arr + 1) << endl;
    cout << "arr[2] = " << *(arr + 2) << endl;
    cout << "arr[3] = " << *(arr + 3) << endl;
    cout << "arr[4] = " << *(arr + 4) << endl;

    // print address of first element
    cout<<"Address of arr[0] = "<<&arr[0]<<endl;
}
int main() {
    emptyArray();
    sizeofarray();
    pointerArray();
    return 0;
}
