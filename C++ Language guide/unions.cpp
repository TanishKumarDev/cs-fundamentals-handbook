#include <iostream>
using namespace std;

// Section 3: Accessing and Assigning Union Members
union Geek_Access {
    int age;
    char grade;
    float GPA;
};

// Section 4: Size of Union
union Geek_Size {
    int age;    // 4 bytes
    float GPA;  // 4 bytes
    double marks; // 8 bytes
};

// Section 5: Nested Unions
struct Employee_Nested {
    char name[50];
    int id;
    union Pay {
        float hourlyRate;
        float salary;
    } payment;
};

// Section 6: Anonymous Unions
struct Employee_Anonymous {
    int id;
    union {
        float hourlyRate;
        float salary;
    };
};

// Section 7: Unions with Pointers
union Data_Pointer {
    int* intPtr;
    char* charPtr;
};

// Section 8: Unions in Functions
union Geek_Function {
    int age;
    float GPA;
};

void printGeek(const Geek_Function& g, bool isAge) {
    if (isAge) {
        cout << "Age: " << g.age << endl;
    } else {
        cout << "GPA: " << g.GPA << endl;
    }
}

int main() {
    // Section 3: Accessing and Assigning Union Members
    cout << "Section 3: Accessing and Assigning Union Members" << endl;
    Geek_Access student1;
    student1.age = 25;
    cout << "Age: " << student1.age << endl; // Output: 25
    student1.grade = 'B';
    cout << "Grade: " << student1.grade << endl; // Output: B
    student1.GPA = 4.5;
    cout << "GPA: " << student1.GPA << endl; // Output: 4.5
    cout << "------------------------" << endl;

    // Section 4: Size of Union
    cout << "Section 4: Size of Union" << endl;
    Geek_Size g;
    cout << "Size of union: " << sizeof(g) << endl; // Output: 8
    cout << "Size of age: " << sizeof(g.age) << endl; // Output: 4
    cout << "Size of GPA: " << sizeof(g.GPA) << endl; // Output: 4
    cout << "Size of marks: " << sizeof(g.marks) << endl; // Output: 8
    cout << "------------------------" << endl;

    // Section 5: Nested Unions
    cout << "Section 5: Nested Unions" << endl;
    Employee_Nested e1;
    e1.id = 101;
    e1.payment.hourlyRate = 300;
    cout << "Employee ID: " << e1.id << endl; // Output: 101
    cout << "Hourly Rate: Rs " << e1.payment.hourlyRate << endl; // Output: 300
    cout << "------------------------" << endl;

    // Section 6: Anonymous Unions
    cout << "Section 6: Anonymous Unions" << endl;
    Employee_Anonymous e2;
    e2.id = 101;
    e2.hourlyRate = 300;
    cout << "Employee ID: " << e2.id << endl; // Output: 101
    cout << "Hourly Rate: Rs " << e2.hourlyRate << endl; // Output: 300
    cout << "------------------------" << endl;

    // Section 7: Unions with Pointers
    cout << "Section 7: Unions with Pointers" << endl;
    Data_Pointer d;
    d.intPtr = new int(42);
    cout << "Int value: " << *d.intPtr << endl; // Output: 42
    delete d.intPtr;
    d.intPtr = nullptr;
    cout << "------------------------" << endl;

    // Section 8: Unions in Functions
    cout << "Section 8: Unions in Functions" << endl;
    Geek_Function student;
    student.age = 25;
    printGeek(student, true); // Output: Age: 25
    student.GPA = 4.0;
    printGeek(student, false); // Output: GPA: 4.0
    cout << "------------------------" << endl;

    return 0;
}
