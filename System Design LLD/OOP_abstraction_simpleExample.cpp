#include <iostream>
using namespace std;

// Abstract class (interface)
class Printer {
public:
    // Only declare what should happen, not how
    virtual void printDocument() = 0;
    virtual ~Printer() {}  // Virtual destructor
};

// Implementation of Printer
class HPPrinter : public Printer {
public:
    void printDocument() override {
        cout << "Printing document using HP printer..." << endl;
    }
};

class CanonPrinter : public Printer {
public:
    void printDocument() override {
        cout << "Printing document using Canon printer..." << endl;
    }
};

// Main function demonstrating abstraction
int main() {
    // Pointer to abstract class
    Printer* myPrinter;

    // Using HP printer
    myPrinter = new HPPrinter();
    myPrinter->printDocument();   // User doesn't know internal logic
    delete myPrinter;

    // Using Canon printer
    myPrinter = new CanonPrinter();
    myPrinter->printDocument();   // Same interface, different behavior
    delete myPrinter;

    return 0;
}
/*

🔍 Simple Definition:
Abstraction = Hiding complex internal implementation and showing only essential features to the user.
Focus on what it does, not how it works.

🧠 Real-Life Analogy: Car
You just use:

    - start()
    - accelerate()
    - brake()

But you don’t know about:

    - fuel injection system
    - engine internals
    - gearbox logic

➡️ You get a simple interface, complex logic is hidden inside = Abstraction
*/

// Notes:

// What Is Abstraction Here?

// Printer class	Acts as interface — only tells what should happen
// printDocument()	Declares the action — hides how it's implemented
// HPPrinter, CanonPrinter	Real implementations — logic hidden from user
// main() user code	Just calls printDocument() — doesn’t care about how it works

