#include <iostream>
#include <string>
using namespace std;

// Globally defined structures to avoid duplication and ensure consistency
struct student {
    string name;
    int age;
    char grade;
};

struct address {
    string city;
    int zip;
};

struct person {
    string name;
    address addr;
};

struct car {
    string brand;
    string model; // Added model field for consistency
    int year;
};

struct employee {
    string name;
    int id;
    address addr;
};

// Function to update car brand (replaces lambda for simplicity)
void updateCar(car& c, string newBrand) {
    c.brand = newBrand;
}

// Function to demonstrate basic structure creation and access
void demoBasicStructure() {
    // Logic: Create and access an unnamed structure
    // Memory: Unnamed struct, variables stored on stack
    struct {
        int myNum;
        string myString;
    } myStructure;
    myStructure.myNum = 1;
    myStructure.myString = "Hello World!";
    cout << "1. Basic Structure:\n";
    cout << "   myNum: " << myStructure.myNum << "\n";
    cout << "   myString: " << myStructure.myString << "\n";
}

// Function to demonstrate one structure in multiple variables
void demoMultipleVariables() {
    // Logic: Use one structure for multiple car variables
    // Memory: Each car variable occupies separate stack memory
    car myCar1, myCar2;
    myCar1.brand = "BMW";
    myCar1.model = "X5";
    myCar1.year = 1999;
    myCar2.brand = "Ford";
    myCar2.model = "Mustang";
    myCar2.year = 1969;
    cout << "2. Multiple Variables:\n";
    cout << "   " << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
    cout << "   " << myCar2.brand << " " << myCar2.model << " " << myCar2.year << "\n";
}

// Function to demonstrate named structures
void demoNamedStructures() {
    // Logic: Reuse named car structure
    // Memory: Consistent structure definition, reusable type
    car myCar1;
    myCar1.brand = "BMW";
    myCar1.model = "X5";
    myCar1.year = 1999;
    car myCar2;
    myCar2.brand = "Ford";
    myCar2.model = "Mustang";
    myCar2.year = 1969;
    cout << "3. Named Structures:\n";
    cout << "   " << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
    cout << "   " << myCar2.brand << " " << myCar2.model << " " << myCar2.year << "\n";
}

// Function to demonstrate challenge task (student structure)
void demoStudentStructure() {
    // Logic: Implement challenge task with student structure
    // Memory: Single student instance, initialized with brace syntax
    student s1 = {"Liam", 35, 'A'};
    cout << "4. Challenge Task - Student Structure:\n";
    cout << "   Name: " << s1.name << "\n";
    cout << "   Age: " << s1.age << "\n";
    cout << "   Grade: " << s1.grade << "\n";
}

// Function to demonstrate additional features
void demoAdditionalFeatures() {
    // Logic: Showcase advanced structure usage
    // 6.1. Initialization
    // Memory: Brace initialization, stack-based
    student s1 = {"Liam", 35, 'A'};
    cout << "5. Additional Features:\n";
    cout << "   Initialization:\n";
    cout << "      " << s1.name << ", " << s1.age << ", " << s1.grade << "\n";

    // 6.2. Nested Structures
    // Memory: Nested structure increases memory footprint, aligned for efficiency
    person p1;
    p1.name = "Alice";
    p1.addr.city = "New York";
    p1.addr.zip = 10001;
    cout << "   Nested Structures:\n";
    cout << "      " << p1.name << ", " << p1.addr.city << ", " << p1.addr.zip << "\n";

    // 6.3. Pointers to Structures
    // Memory: Pointer stores address, minimal overhead
    car myCar = {"Toyota", "Camry", 2020};
    car* ptr = &myCar;
    cout << "   Pointers to Structures:\n";
    cout << "      " << ptr->brand << ", " << ptr->model << ", " << ptr->year << "\n";

    // 6.4. References to Structures
    // Memory: Reference avoids copying, modifies original
    updateCar(myCar, "Tesla");
    cout << "   References to Structures:\n";
    cout << "      " << myCar.brand << ", " << myCar.model << ", " << myCar.year << "\n";

    // 6.5. Arrays of Structures
    // Memory: Contiguous array, size = sizeof(car) * 2
    car cars[2] = {{"BMW", "X5", 1999}, {"Ford", "Mustang", 1969}};
    cout << "   Arrays of Structures:\n";
    cout << "      " << cars[0].brand << ", " << cars[1].year << "\n";
}

// Function to demonstrate employee database
void demoEmployeeDatabase() {
    // Logic: Manage employee records with nested structures and arrays
    // Memory: Array of employees, each with nested address
    employee staff[2] = {{"Alice", 101, {"New York", 10001}}, {"Bob", 102, {"Boston", 02101}}};
    cout << "6. Employee Database:\n";
    cout << "   " << staff[0].name << ", ID: " << staff[0].id << ", City: " << staff[0].addr.city << "\n";
    cout << "   " << staff[1].name << ", ID: " << staff[1].id << ", City: " << staff[1].addr.city << "\n";
}

// Main function: Entry point of the program
int main() {
    cout << "=== C++ Structures Demonstration ===" << endl;

    demoBasicStructure();
    demoMultipleVariables();
    demoNamedStructures();
    demoStudentStructure();
    demoAdditionalFeatures();
    demoEmployeeDatabase();

    cout << "\n7. Exercise Answer:\n";
    cout << "   Q: What is a structure in C++? Answer: A way to group related variables of different data types\n";

    return 0;
}