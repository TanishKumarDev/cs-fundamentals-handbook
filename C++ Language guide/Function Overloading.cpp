#include <bits/stdc++.h>
using namespace std;


/*
Function Overloading:

Function overloading allows multiple functions to have the same name, as long as their parameters are different in type or number:


Function Overloading WHY? :

- Without Function Overloading

int plusFuncInt(int x, int y) {
  return x + y;
}

double plusFuncDouble(double x, double y) {
  return x + y;
}

int main() {
  int myNum1 = plusFuncInt(8, 5);
  double myNum2 = plusFuncDouble(4.3, 6.26);

  cout << "Int: " << myNum1 << "\n";
  cout << "Double: " << myNum2;
  return 0;
}

- With Function Overloading

int plusFunc(int x, int y) {
  return x + y;
}

double plusFunc(double x, double y) {
  return x + y;
}

Problem: We had to create two different function names for the same logic.

Using Function Overloading
Instead of defining two functions that should do the same thing, it is better to overload one.

In the example below, we overload the plusFunc function to work for both int and double:


*/

// Normal (non-overloaded) functions
int plusFuncInt(int x, int y) {
    return x + y;
}

double plusFuncDouble(double x, double y) {
    return x + y;
}

// Overloaded function (same name, different parameter types)
int plusFunc(int x, int y) {
    return x + y;
}

double plusFunc(double x, double y) {
    return x + y;
}


int main()
{
    // Without function overloading
    int myNum1 = plusFuncInt(8, 5);
    double myNum2 = plusFuncDouble(4.3, 6.26);
    cout << "Without Overloading:\n";
    cout << "Int: " << myNum1 << "\n";
    cout << "Double: " << myNum2 << "\n\n";

    // With function overloading
    int myNum3 = plusFunc(8, 5);             // Calls int version
    double myNum4 = plusFunc(4.3, 6.26);     // Calls double version
    cout << "With Overloading:\n";
    cout << "Int: " << myNum3 << "\n";
    cout << "Double: " << myNum4 << "\n";

    return 0;
}