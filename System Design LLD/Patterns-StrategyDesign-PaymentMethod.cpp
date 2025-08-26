// 🚀 Strategy Design Pattern

// It is a Behavioral Design Pattern.

// It lets you define a family of algorithms (strategies), put them in separate classes, and make them interchangeable.

// The client (main code) can choose which strategy (algorithm) to use at runtime.

// 👉 In simple words:
// Instead of hardcoding multiple if-else conditions to choose an algorithm, you can plug-and-play different strategies.

// 🧠 Example Intuition

// Suppose you’re making a Payment System.

// Users can pay with Credit Card, PayPal, or UPI.

// If you hardcode it in if-else, it will become messy.

// Instead, you define a Strategy Interface → PaymentStrategy, and then create concrete strategies: CreditCardPayment, PayPalPayment, UPIPayment.

// At runtime, the user chooses which payment method to use.

// 🎯 Key Points:

// Strategy Interface → defines a method (pay) all strategies must implement.

// Concrete Strategies → implement the algorithm (CreditCard, PayPal, UPI).

// Context → takes a strategy object and delegates the work to it.

// Client → decides which strategy to use at runtime.

// 👉 Real-World Uses:

// Payment systems (different payment methods).

// Sorting algorithms (quick sort, merge sort, heap sort).

// Compression (ZIP, RAR, GZIP).

// Pathfinding in maps (shortest path vs fastest route).

#include <bits/stdc++.h>
using namespace std;

// 1. Strategy Interface
class PaymentStrategy{
    public: 
    virtual void pay(int amount) = 0; // pure virtual functions
    virtual ~PaymentStrategy() {}
};

// 2. Concrete Strategies

// Credit Card Payment
class CreditCardPayment : public PaymentStrategy{
    public:
    void pay(int amount) override{
        cout<<"Paid "<<amount<<" using Credit Card."<<endl;
    }
};

// PayPal Payment
class PayPalPayment : public PaymentStrategy{
    public:
    void pay(int amount) override{
        cout<<"Paid "<<amount<<" using PayPal."<<endl;
    }
};

// UPI Payment
class UPIPayment : public PaymentStrategy{
    public:
    void pay(int amount) override{
        cout<<"Paid "<<amount<<" using UPI."<<endl;
    }
};

// 3. Context (uses a Strategy)
class PaymentContext{
    private:
    PaymentStrategy* strategy;
    public:
    PaymentContext(PaymentStrategy* strategy) : strategy(strategy) {}
    void executePayment(int amount){
        strategy->pay(amount);
    }
};

// 4. Client Code
int main()
{
    PaymentContext* context;

    // User selects Credit Card Payment
    context = new PaymentContext(new CreditCardPayment());
    context->executePayment(100);

    // User selects PayPal Payment
    context = new PaymentContext(new PayPalPayment());
    context->executePayment(200);

    // User selects UPI Payment
    context = new PaymentContext(new UPIPayment());
    context->executePayment(300);

    return 0;
}