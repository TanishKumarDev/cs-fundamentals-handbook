#include <iostream>
#include <string>
#include <functional>
using namespace std;

// Global Structs
struct student {
    string name;
    int score;
};

struct Car {
    string brand;
    int year;
};

// Global variable
int globalVar = 5;

// ---------- Helper Functions ----------

// Used in demoParameters
void paramFunction(const string& fname) {
    cout << fname << " Refsnes\n";
}

// Used in demoDefaultParameters
void defaultParamFunction(const string& country = "Norway") {
    cout << country << "\n";
}

// Used in demoMultipleParameters
void multiParamFunction(const string& fname, int age) {
    cout << fname << " Refsnes. " << age << " years old.\n";
}

// Used in demoReturnValues
int sumFunction(int x, int y) {
    return x + y;
}
int doubleGame(int x) {
    return x * 2;
}

// Used in demoPassArray
void arrayFunction(int myNumbers[], int size) {
    for (int i = 0; i < size; i++) {
        myNumbers[i] *= 2;
        cout << myNumbers[i] << "\n";
    }
}

// Used in demoPassStructure
void printCar(const Car& c) {
    cout << "Brand: " << c.brand << ", Year: " << c.year << "\n";
}
void updateYear(Car& c) {
    c.year++;
}

// Used in demoPassByValueAndReference
void modifyValue(int x) {
    x = 100;
}
void modifyReference(int& x) {
    x = 100;
}

// Used in demoVariableScope
void scopeFunction() {
    int globalVar = 22; // Local shadows global
    cout << "Local: " << globalVar << "\n";
}

// Used in demoRecursion
int sum(int k) {
    if (k <= 0) return 0;
    return k + sum(k - 1);
}
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Used in demoAdvancedFeatures
void print(int n) { cout << n << "\n"; }
void print(const string& s) { cout << s << "\n"; }
template<typename T>
T maxT(T a, T b) { return a > b ? a : b; }
int add(int a, int b) { return a + b; }
constexpr int factorialConst(int n) {
    return n <= 1 ? 1 : n * factorialConst(n - 1);
}
inline int square(int x) { return x * x; }
void counter() {
    static int count = 0;
    cout << "Call: " << ++count << "\n";
}

// Used in demoStudentManagement
string getStatus(const student& s, int threshold = 60) {
    return s.score >= threshold ? "Pass" : "Fail";
}
void updateScore(student& s, int newScore) {
    s.score = newScore;
}

// ---------- Demo Functions ----------

void demoBasicFunction() {
    cout << "1. Basic Function Call:\n";
    auto basicFunction = []() {
        cout << "I just got executed!\n";
    };
    basicFunction();
    basicFunction();
}

void demoDeclarationDefinition() {
    cout << "2. Declaration and Definition:\n";
    cout << "I just got executed!\n";
}

void demoParameters() {
    cout << "3. Parameters:\n";
    paramFunction("Liam");
    paramFunction("Jenny");
    paramFunction("Anja");
}

void demoDefaultParameters() {
    cout << "4. Default Parameters:\n";
    defaultParamFunction("Sweden");
    defaultParamFunction();
    defaultParamFunction("USA");
}

void demoMultipleParameters() {
    cout << "5. Multiple Parameters:\n";
    multiParamFunction("Liam", 3);
    multiParamFunction("Jenny", 14);
}

void demoReturnValues() {
    cout << "6. Return Values:\n";
    int z = sumFunction(5, 3);
    cout << "   Sum: " << z << "\n";
    cout << "   Doubling Game:\n";
    for (int i = 1; i <= 5; i++) {
        cout << "      Double of " << i << " is " << doubleGame(i) << "\n";
    }
}

void demoPassArray() {
    int myNumbers[5] = {10, 20, 30, 40, 50};
    cout << "7. Pass Array:\n";
    arrayFunction(myNumbers, 5);
    cout << "   Modified First Element: " << myNumbers[0] << "\n";
}

void demoPassStructure() {
    Car myCar = {"Toyota", 2020};
    cout << "8. Pass Structure:\n";
    printCar(myCar);
    cout << "   Original Year: " << myCar.year << "\n";
    updateYear(myCar);
    cout << "   Updated: The " << myCar.brand << " is now from year " << myCar.year << "\n";
}

void demoPassByValueAndReference() {
    int val = 5;
    cout << "9. Pass-by-Value vs. Pass-by-Reference:\n";
    modifyValue(val);
    cout << "   After Value: " << val << "\n";
    modifyReference(val);
    cout << "   After Reference: " << val << "\n";
}

void demoVariableScope() {
    cout << "10. Variable Scope:\n";
    scopeFunction();
    cout << "   Global: " << globalVar << "\n";
}

void demoRecursion() {
    cout << "11. Recursion:\n";
    cout << "   Sum(10): " << sum(10) << "\n";
    cout << "   Factorial(5): " << factorial(5) << "\n";
}

void demoLambdaFunctions() {
    cout << "12. Lambda Functions:\n";
    auto add = [](int a, int b) { return a + b; };
    cout << "   Add(3,4): " << add(3, 4) << "\n";

    int x = 10;
    auto showValue = [x]() { cout << "Value: " << x << "\n"; };
    auto showRef = [&x]() { cout << "Ref: " << x << "\n"; };
    x = 20;
    showValue();
    showRef();

    auto message = []() { cout << "Hello World!\n"; };
    auto callTwice = [](function<void()> func) {
        func(); func();
    };
    cout << "   Passing Lambda:\n";
    callTwice(message);

    cout << "   Lambda in Loop:\n";
    for (int i = 1; i <= 3; i++) {
        auto show = [i]() { cout << "      Number: " << i << "\n"; };
        show();
    }
}

void demoAdvancedFeatures() {
    cout << "13. Advanced Features:\n";
    cout << "   Overloading:\n";
    print(42);
    print("Test");
    cout << "   Template Max: " << maxT(5.5, 3.3) << "\n";
    int (*funcPtr)(int, int) = add;
    cout << "   Function Pointer: " << funcPtr(5, 3) << "\n";
    cout << "   Constexpr Factorial(4): " << factorialConst(4) << "\n";
    cout << "   Inline Square: " << square(3) << "\n";
    cout << "   Static Counter:\n";
    counter();
    counter();
}

void demoStudentManagement() {
    student students[2] = {{"Liam", 85}, {"Jenny", 55}};
    cout << "14. Student Management:\n";
    auto format = [](const student& s) {
        cout << "   " << s.name << ": " << s.score << "\n";
    };
    for (int i = 0; i < 2; i++) {
        format(students[i]);
        cout << "   Status: " << getStatus(students[i]) << "\n";
    }
    updateScore(students[1], 75);
    cout << "   Updated Jenny: " << getStatus(students[1]) << "\n";
}

// ---------- Main ----------
int main() {
    cout << "=== C++ Functions A to Z Comprehensive Demonstration ===\n";

    demoBasicFunction();
    demoDeclarationDefinition();
    demoParameters();
    demoDefaultParameters();
    demoMultipleParameters();
    demoReturnValues();
    demoPassArray();
    demoPassStructure();
    demoPassByValueAndReference();
    demoVariableScope();
    demoRecursion();
    demoLambdaFunctions();
    demoAdvancedFeatures();
    demoStudentManagement();

    cout << "\n15. Exercise Answers:\n";
    cout << "   Q1: What is a function in C++?\n";
    cout << "      Answer: A block of code that runs only when called\n";
    cout << "   Q2: What is a parameter in a C++ function?\n";
    cout << "      Answer: A variable inside the function that receives data\n";
    cout << "   Q3: What is a default parameter value in C++?\n";
    cout << "      Answer: A value assigned to a parameter if no argument is provided\n";
    cout << "   Q4: What does the void keyword indicate in a function?\n";
    cout << "      Answer: The function does not return a value\n";
    cout << "   Q5: What is a local variable in C++?\n";
    cout << "      Answer: A variable that can only be accessed within the function it was declared\n";
    cout << "   Q6: What is recursion?\n";
    cout << "      Answer: A technique of making a function call itself\n";

    return 0;
}
