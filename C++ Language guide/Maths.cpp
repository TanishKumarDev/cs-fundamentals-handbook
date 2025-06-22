#include <iostream>
#include <cmath>
#include <algorithm> // For max/min
using namespace std;

// Define M_PI for portability (not guaranteed in <cmath>)
const double M_PI = 3.14159265358979323846;

// Function to demonstrate max and min
void demoMaxMin() {
    // Logic: Find highest and lowest values
    int x = 5, y = 10;
    cout << "Max of " << x << ", " << y << ": " << max(x, y) << endl;
    cout << "Min of " << x << ", " << y << ": " << min(x, y) << endl;
}

// Function to demonstrate provided <cmath> functions
void demoProvidedMathFunctions() {
    // Logic: Use sqrt, round, log
    cout << "Square root of 64: " << sqrt(64) << endl;
    cout << "Round 2.6: " << round(2.6) << endl;
    cout << "Natural log of 2: " << log(2) << endl;
}

// Function to demonstrate additional <cmath> functions
void demoAdditionalMathFunctions() {
    // Logic: Showcase a variety of <cmath> functions
    double x = -5.5, y = 2.3, z = 2.0;
    cout << "abs(" << x << "): " << abs(x) << endl;
    cout << "ceil(" << y << "): " << ceil(y) << endl;
    cout << "floor(" << y << "): " << floor(y) << endl;
    cout << "pow(" << z << ", 3): " << pow(z, 3) << endl;
    cout << "exp(" << z << "): " << exp(z) << endl;
    cout << "log10(" << z << "): " << log10(z) << endl;
    cout << "sin(π/2): " << sin(M_PI / 2) << endl;
    cout << "cos(0): " << cos(0) << endl;
    cout << "tan(π/4): " << tan(M_PI / 4) << endl;
    cout << "hypot(3, 4): " << hypot(3, 4) << endl;
    cout << "cbrt(8): " << cbrt(8) << endl;
}

// Function to demonstrate circle calculator
void demoCircleCalculator() {
    // Logic: Calculate circle properties
    double radius = 5.0;
    double area = M_PI * pow(radius, 2);
    double circumference = 2 * M_PI * radius;
    double x = 3.0, y = 4.0;
    double distance = hypot(x, y);
    cout << "Circle with radius " << radius << ":" << endl;
    cout << "Area: " << area << endl;
    cout << "Circumference: " << circumference << endl;
    cout << "Distance from (0,0) to (" << x << ", " << y << "): " << distance << endl;
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ Math Demonstration ===" << endl;

    cout << "\n1. Max and Min Functions:" << endl;
    demoMaxMin();

    cout << "\n2. Provided <cmath> Functions:" << endl;
    demoProvidedMathFunctions();

    cout << "\n3. Additional <cmath> Functions:" << endl;
    demoAdditionalMathFunctions();

    cout << "\n4. Circle Calculator:" << endl;
    demoCircleCalculator();

    return 0;
}
