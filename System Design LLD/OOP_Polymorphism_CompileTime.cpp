/*
Polymorphism is the ability of an object to take on multiple forms. 
In C++, it is the ability of an object to behave in different ways depending on the context.

There are two types of polymorphism in C++:

1. Compile-time Polymorphism:
   - Function Overloading (same name, different parameters)
   - Operator Overloading (different symbols, but same operation)
   - Template Metaprogramming (code gets generated at compile time)

2. Runtime Polymorphism:
   - Function Overriding (same name, same parameters, different implementation)
   - Virtual Functions (child class provides different implementation than parent class)

*/

// Code Example: Function Overloading
#include <iostream>
using namespace std;

class Calculator {
    public:
    // Add two integers
    int add(int a, int b) {
        return a + b;
    }
    
    // Add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }
    
    // Add two floats
    float add(float a, float b) {
        return a + b;
    }
    
    // Add three floats
    float add(float a, float b, float c) {
        return a + b + c;
    }
};

// Code Example: Operator Overloading 
class Complex {
    int real, imag;
    
    public:
    Complex(int r, int i) {
        real = r;
        imag = i;
    }
    
    // Overloading '+' operator
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }
    
    void print() {
        cout << real << " + " << imag << "i" << endl;
    }
};


// Main function
int main() {

    // Code Example: Function Overloading
    Calculator calc;
    
    cout << "add(2, 3) = " << calc.add(2, 3) << endl;               // int version
    cout << "add(2, 3, 4) = " << calc.add(2, 3, 4) << endl;         // 3-int version
    cout << "add(1.5f, 2.3f) = " << calc.add(1.5f, 2.3f) << endl;   // float version
    cout << "add(1.5f, 2.3f, 3.4f) = " << calc.add(1.5f, 2.3f, 3.4f) << endl; // 3-float version
    
    
    // Code Example: Operator Overloading
    Complex c1(2, 3), c2(4, 5);
    Complex sum = c1 + c2;  // '+' overloaded
    sum.print();  
    return 0;
}

/*
🔍 Simple Definition:
Polymorphism = One function behaves differently in different contexts.

Poly = many, Morphism = forms
Means same interface, different behavior

🧠 Real-Life Analogy: Remote Control
Pressing "Play" button:
    - On TV → plays show
    - On AC → resumes cooling
    - On Music System → plays song

➡️ Same action (play) triggers different behavior depending on the device = Polymorphism

*/