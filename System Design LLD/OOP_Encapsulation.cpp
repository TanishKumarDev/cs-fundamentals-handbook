#include <iostream>
using namespace std;

class BankAccount {
private:
    string owner;
    int balance;  // Data is hidden (private)

public:
    // Constructor
    BankAccount(string name, int initialBalance) {
        owner = name;
        balance = initialBalance;
    }

    // Public method to deposit money (controlled access)
    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " to " << owner << "'s account." << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Public method to withdraw money
    void withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << ". Remaining balance: " << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    // Getter to check balance
    int getBalance() {
        return balance;
    }
};

// Main Program to demonstrate Encapsulation
int main() {
    BankAccount myAcc("Tanish", 1000);

    // Direct access (this will give error)
    // myAcc.balance = 5000;

    // Use only public methods to access/modify
    myAcc.deposit(500);
    myAcc.withdraw(200);
    cout << "Current Balance: " << myAcc.getBalance() << endl;

    return 0;
}


// 🔍 Simple Definition:
// Encapsulation is the process of wrapping data and methods into one unit, and restricting direct access to the data using access modifiers (private, public).

// Data is hidden (private)
// Access is only allowed via methods (getters/setters)

// 🧠 Real-Life Analogy:
// Think of an ATM.

// You:
// insertCard()
// enterPin()
// withdraw()

// But you cannot directly:
// open the cash bin of the ATM
// or access the balance variable

// That's encapsulation → Access controlled through functions only
