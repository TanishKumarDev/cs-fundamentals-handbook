#include <iostream>
using namespace std;

// Section 3: Initialize Structure Members
struct Point_Init {
    int x, y;
};

// Section 4: Access and Modify Members
struct Point_Access {
    int x, y;
};

// Section 5: Member Functions
struct Point_Sum {
    int x, y;
    int sum() { // Member function
        return x + y;
    }
};

// Section 5: Advanced Example with Constructors and Destructors
struct Point_Advanced {
private:
    int x, y;
public:
    Point_Advanced(int a = 1, int b = 1) : x(a), y(b) {} // Constructor
    void show() {
        cout << x << ", " << y << endl;
    }
    ~Point_Advanced() { // Destructor
        cout << "Destroyed Point Variable" << endl;
    }
};

// Section 6: Size of Structure
struct GfG_Size {
    char c; // 1 byte
    int x, y; // 4 bytes each
};

// Section 7: Typedef with Structures
typedef struct GeeksforGeeks_Typedef {
    int x, y;
} GfG;

// Section 8: Nested Structures (Named Inner Structure)
struct Inner {
    int a, b;
};

struct Outer {
    Inner in;
    int x, y;
};

// Section 8: Nested Structures (Anonymous Inner Structure)
struct Outer_Anonymous {
    struct {
        int a, b;
    } in;
    int x, y;
};

// Section 9: Pointer to Structure
struct GfG_Pointer {
    int count;
    void showCount() {
        cout << count << endl;
    }
};

// Section 10: Self-Referential Structures
struct GfG_Self {
    int val;
    GfG_Self* next;
};

// Section 11: Structures with Functions
struct Point_Function {
    int x, y;
};

void printPoint(const Point_Function& p) { // Pass by const reference
    cout << p.x << ", " << p.y << endl;
}

// Section 12: Bit Fields
struct Flags {
    unsigned int flag1 : 1; // 1 bit
    unsigned int flag2 : 2; // 2 bits
};

int main() {
    // Section 3: Initialize Structure Members
    cout << "Section 3: Initialize Structure Members" << endl;
    Point_Init p1 = {0, 1};
    cout << "p1: " << p1.x << ", " << p1.y << endl; // Output: p1: 0, 1
    // C++20 designated initializers (commented out for pre-C++20 compatibility)
    // Point_Init p2 = {.x = 2, .y = 3};
    // cout << "p2: " << p2.x << ", " << p2.y << endl; // Output: p2: 2, 3
    cout << "------------------------" << endl;

    // Section 4: Access and Modify Members
    cout << "Section 4: Access and Modify Members" << endl;
    Point_Access p = {0, 1};
    cout << "Original: " << p.x << ", " << p.y << endl; // Output: 0, 1
    p.x = 99;
    cout << "Modified: " << p.x << ", " << p.y << endl; // Output: 99, 1
    cout << "------------------------" << endl;

    // Section 5: Member Functions
    cout << "Section 5: Member Functions" << endl;
    Point_Sum s = {0, 1};
    cout << "Sum: " << s.sum() << endl; // Output: 1
    cout << "------------------------" << endl;

    // Section 5: Advanced Example with Constructors and Destructors
    cout << "Section 5: Advanced Example with Constructors and Destructors" << endl;
    Point_Advanced s1;
    Point_Advanced s2(99, 1001);
    s1.show(); // Output: 1, 1
    s2.show(); // Output: 99, 1001
    // Destructors called automatically at scope exit
    // Output: Destroyed Point Variable (for s2)
    // Output: Destroyed Point Variable (for s1)
    cout << "------------------------" << endl;

    // Section 6: Size of Structure
    cout << "Section 6: Size of Structure" << endl;
    cout << "Size of GfG: " << sizeof(GfG_Size) << endl; // Output: 12
    cout << "------------------------" << endl;

    // Section 7: Typedef with Structures
    cout << "Section 7: Typedef with Structures" << endl;
    GfG s_typedef = {0, 1};
    cout << s_typedef.x << ", " << s_typedef.y << endl; // Output: 0, 1
    cout << "------------------------" << endl;

    // Section 8: Nested Structures (Named Inner Structure)
    cout << "Section 8: Nested Structures (Named Inner Structure)" << endl;
    Outer obj = {{1, 2}, 10, 20};
    cout << "Inner: " << obj.in.a << ", " << obj.in.b << endl; // Output: 1, 2
    cout << "Outer: " << obj.x << ", " << obj.y << endl; // Output: 10, 20
    cout << "------------------------" << endl;

    // Section 8: Nested Structures (Anonymous Inner Structure)
    cout << "Section 8: Nested Structures (Anonymous Inner Structure)" << endl;
    Outer_Anonymous obj_anon = {{1, 2}, 10, 20};
    cout << "Inner: " << obj_anon.in.a << ", " << obj_anon.in.b << endl; // Output: 1, 2
    cout << "Outer: " << obj_anon.x << ", " << obj_anon.y << endl; // Output: 10, 20
    cout << "------------------------" << endl;

    // Section 9: Pointer to Structure
    cout << "Section 9: Pointer to Structure" << endl;
    GfG_Pointer gfg = {224};
    GfG_Pointer* sptr = &gfg;
    sptr->showCount(); // Output: 224
    cout << "------------------------" << endl;

    // Section 10: Self-Referential Structures
    cout << "Section 10: Self-Referential Structures" << endl;
    GfG_Self node1 = {1, nullptr};
    GfG_Self node2 = {2, nullptr};
    node1.next = &node2;
    cout << "Node1 value: " << node1.val << endl; // Output: 1
    cout << "Node2 value: " << node1.next->val << endl; // Output: 2
    cout << "------------------------" << endl;

    // Section 11: Structures with Functions
    cout << "Section 11: Structures with Functions" << endl;
    Point_Function p_func = {5, 10};
    printPoint(p_func); // Output: 5, 10
    cout << "------------------------" << endl;

    // Section 12: Bit Fields
    cout << "Section 12: Bit Fields" << endl;
    Flags f = {1, 3};
    cout << "Flag1: " << f.flag1 << ", Flag2: " << f.flag2 << endl; // Output: 1, 3
    cout << "Size: " << sizeof(f) << endl; // Output: 4
    cout << "------------------------" << endl;

    return 0;
}
