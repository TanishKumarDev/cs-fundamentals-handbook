#include <iostream>
using namespace std;

// Section 1: Definition and Initialization of Structure Pointers
struct Point_Init {
    int x, y;
};

// Section 2: Accessing Structure Members via Pointers
struct Point_Access {
    int value;
};

// Section 3: Structure Pointers with Nested Structures
struct GFG {
    int x, y;
};

struct Square {
    GFG left;
    GFG right;
};

void area_Square(Square* s) {
    int area = (s->right.x) * (s->left.x);
    cout << "Area: " << area << endl;
}

// Section 4: Dynamic Allocation of Structures
struct Point_Dynamic {
    int x, y;
};

// Section 5: Structure Pointers in Functions
struct Point_Function {
    int x, y;
};

void printPoint(Point_Function* p) {
    cout << "Point: " << p->x << ", " << p->y << endl;
}

// Section 6: Self-Referential Structures
struct Node {
    int val;
    Node* next;
};

// Section 7: Array of Structure Pointers
struct Point_Array {
    int x, y;
};

int main() {
    // Section 1: Definition and Initialization of Structure Pointers
    cout << "Section 1: Definition and Initialization of Structure Pointers" << endl;
    Point_Init p = {1, 2};
    Point_Init* ptr = &p;
    cout << "Address: " << ptr << endl; // Output: Memory address of p
    cout << "x: " << ptr->x << ", y: " << ptr->y << endl; // Output: x: 1, y: 2
    cout << "------------------------" << endl;

    // Section 2: Accessing Structure Members via Pointers
    cout << "Section 2: Accessing Structure Members via Pointers" << endl;
    Point_Access g = {10};
    Point_Access* ptr_access = &g;
    cout << "Value: " << ptr_access->value << endl; // Output: 10
    ptr_access->value = 20;
    cout << "Modified Value: " << ptr_access->value << endl; // Output: 20
    cout << "------------------------" << endl;

    // Section 3: Structure Pointers with Nested Structures
    cout << "Section 3: Structure Pointers with Nested Structures" << endl;
    Square s = {{4, 4}, {4, 4}};
    Square* ptr_square = &s;
    area_Square(ptr_square); // Output: Area: 16
    cout << "------------------------" << endl;

    // Section 4: Dynamic Allocation of Structures
    cout << "Section 4: Dynamic Allocation of Structures" << endl;
    Point_Dynamic* ptr_dynamic = new Point_Dynamic{5, 10};
    cout << "x: " << ptr_dynamic->x << ", y: " << ptr_dynamic->y << endl; // Output: x: 5, y: 10
    delete ptr_dynamic;
    ptr_dynamic = nullptr;
    cout << "------------------------" << endl;

    // Section 5: Structure Pointers in Functions
    cout << "Section 5: Structure Pointers in Functions" << endl;
    Point_Function p_func = {3, 4};
    printPoint(&p_func); // Output: Point: 3, 4
    cout << "------------------------" << endl;

    // Section 6: Self-Referential Structures
    cout << "Section 6: Self-Referential Structures" << endl;
    Node node1 = {1, nullptr};
    Node node2 = {2, nullptr};
    node1.next = &node2;
    cout << "Node1 val: " << node1.val << endl; // Output: 1
    cout << "Node2 val: " << node1.next->val << endl; // Output: 2
    cout << "------------------------" << endl;

    // Section 7: Array of Structure Pointers
    cout << "Section 7: Array of Structure Pointers" << endl;
    Point_Array p1 = {1, 2}, p2 = {3, 4}, p3 = {5, 6};
    Point_Array* arr[3] = {&p1, &p2, &p3};
    for (int i = 0; i < 3; i++) {
        cout << "Point " << i + 1 << ": " << arr[i]->x << ", " << arr[i]->y << endl;
    }
    // Output:
    // Point 1: 1, 2
    // Point 2: 3, 4
    // Point 3: 5, 6
    cout << "------------------------" << endl;

    return 0;
}