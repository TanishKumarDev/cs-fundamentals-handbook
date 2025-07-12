#include <bits/stdc++.h>
using namespace std;
// 👉 Basic Function
void printHello() { // define function
    cout << "Hello" << endl;
}


// 👉 Return Type
// We have seen an example of function that does not return anything. But functions can return some value as a result of its execution. The type of this value should be defined as the return_type of the function. 

// Note: Only one value can be returned from the function, and it must be of the same type as of function's return type.

// Example
int add(int a, int b) {
    return a + b;
}

// 👉 Parameters or Arguments
// A function can also take some input data to process. These values are called function arguments and are supplied to the function at the function call. To receive these values, we define placeholder variables called parameter inside parenthesis in function definition. They should be specified with their types and names.

// In above example a and b are parameters and 1 and 2 are arguments
// A function can only take as many arguments as specified in the function definition and it is compulsory to pass them while calling it. Also, they should be of same type as in the function definition.


// 👉 Forward Declaration
// In C++, a function must be defined before its call. Otherwise, compiler will throw an error. To resolve this, we can just declare the function before the call and definition to inform the compiler about function's name and return type. This is called forward declaration or just function declarations.

// Note: Function declarations are compulsory, but the function definition already contains the function declaration as a part of it, so it is not explicitly needed when function is defined at the start.
// Note: Function declarations are compulsory, but the function definition already contains the function declaration as a part of it, so it is not explicitly needed when function is defined at the start.

// 👉 Library Functions 
// C++ also provides some in-build functions that are already defined inside different libraries to simplify some commonly performed tasks. These functions are Library Functions which can be directly called to perform the task.

// Example
/*
    int main() {
    int n = 3;
    int m = 6;
    
    // Call library function max() that
    // returns maximum value between two
    // numbers
    cout << max(3, 6); // Output: 6
    return 0;
    }
*/

// 👉 Default Arguments
// Earlier, we said that it is compulsory to pass all the arguments in the function call. But C++ also provides a work around for this. For each function argument, a default value can be defined that will be used when no value is passed for that argument in the function call. These are called default arguments in C++. If a function has more than one parameter, default values are assigned from right to left. This means that default values can only be provided for the rightmost parameters.
int sum(int a, int b = 0, int c = 0) {
    return a + b + c;
}

int main()
{
    printHello(); // call function
    cout<<add(1, 2)<<endl;
    cout<<sum(1)<<endl;
    cout<<sum(1,2)<<endl;
    cout<<sum(1, 2, 3);
    return 0;


}

