#include <iostream>
#include <string>

// Base class for payment processing
class PaymentProcessor {
public:
    virtual void processPayment(double amount) = 0; // Pure virtual function
};

// Credit card payment processor
class CreditCardPaymentProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override {
        std::cout << "Processing credit card payment of $" << amount << std::endl;
    }
};

// PayPal payment processor
class PayPalPaymentProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override {
        std::cout << "Processing PayPal payment of $" << amount << std::endl;
    }
};

void processPayment(PaymentProcessor* processor, double amount) {
    processor->processPayment(amount);
}

int main() {
    CreditCardPaymentProcessor creditCardProcessor;
    PayPalPaymentProcessor payPalProcessor;

    processPayment(&creditCardProcessor, 100.00); // Processing credit card payment
    processPayment(&payPalProcessor, 150.00);     // Processing PayPal payment

    return 0;
}

// 2. Open/Closed Principle

//  "Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification" which means you should be able to extend a class behavior, without modifying it.

// Instead of modifying the existing PaymentProcessor class to add PayPal support, you can create a new class called PayPalPaymentProcessor that extends the PaymentProcessor class. This way, the PaymentProcessor class remains closed for modification but open for extension, adhering to the Open-Closed Principle.

// Explanation of the above code:

// Base Class (PaymentProcessor): This is an abstract base class with a pure virtual function processPayment(). It defines a common interface for all payment processors.
// CreditCardPaymentProcessor: This class implements the payment processing logic for credit card payments.
// PayPalPaymentProcessor: This new class extends the functionality by implementing the payment processing for PayPal payments.
// Main Function: The processPayment function takes a pointer to a PaymentProcessor and calls the processPayment() method. This allows you to use any processor that implements the PaymentProcessor interface without changing existing code.