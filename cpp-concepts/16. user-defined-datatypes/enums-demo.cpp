#include <bits/stdc++.h>
using namespace std;

// An enum (enumeration) is a user-defined data type that assigns names to integer constants, making the code more readable.
// Think of it as a way to define meaningful names for a group of related values.

//  Traffic Light
enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};
void takeAction(TrafficLight light) {
    switch (light) {
        case RED:
        cout << "STOP 🚦" << endl;
        break;
        case YELLOW:
        cout << "READY ⚠️" << endl;
        break;
        case GREEN:
            cout << "GO ✅" << endl;
            break;
    }
}

//  Order Status
enum class OrderStatus {
    Pending,
    Shipped,
    Delivered,
    Cancelled
};

void printStatus(OrderStatus status) {
    switch (status) {
        case OrderStatus::Pending:
            cout << "Order Pending 🕒" << endl;
            break;
        case OrderStatus::Shipped:
            cout << "Order Shipped 🚚" << endl;
            break;
        case OrderStatus::Delivered:
            cout << "Order Delivered 📦" << endl;
            break;
        case OrderStatus::Cancelled:
            cout << "Order Cancelled ❌" << endl;
            break;
    }
}

int main() {
    //  Traffic Light
    TrafficLight light = RED;

    takeAction(light);
    
    light = YELLOW;
    takeAction(light);

    light = GREEN;
    takeAction(light);

    //  Order Status
    OrderStatus status = OrderStatus::Pending;
    printStatus(status);

    status = OrderStatus::Delivered;
    printStatus(status);
    return 0;
}

