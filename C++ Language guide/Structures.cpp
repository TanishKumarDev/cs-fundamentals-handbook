#include <iostream>
#include <string>

int main() {
    // Section 1: Anonymous Structure
    std::cout << "Section 1: Anonymous Structure" << std::endl;
    struct {
        int myNum;
        std::string myString;
    } myStructure;

    myStructure.myNum = 1;
    myStructure.myString = "Hello World!";
    std::cout << "myNum: " << myStructure.myNum << std::endl;
    std::cout << "myString: " << myStructure.myString << std::endl;

    // Section 2: One Structure, Multiple Variables
    std::cout << "\nSection 2: One Structure, Multiple Variables" << std::endl;
    struct {
        std::string brand;
        std::string model;
        int year;
    } myCar1, myCar2;

    myCar1.brand = "BMW";
    myCar1.model = "X5";
    myCar1.year = 1999;

    myCar2.brand = "Ford";
    myCar2.model = "Mustang";
    myCar2.year = 1969;

    std::cout << "Car 1: " << myCar1.brand << " " << myCar1.model << " " << myCar1.year << std::endl;
    std::cout << "Car 2: " << myCar2.brand << " " << myCar2.model << " " << myCar2.year << std::endl;

    // Section 3: Named Structure
    std::cout << "\nSection 3: Named Structure" << std::endl;
    struct Car {
        std::string brand;
        std::string model;
        int year;
    };

    Car car1, car2;
    car1.brand = "Tesla";
    car1.model = "Model S";
    car1.year = 2020;

    car2.brand = "Toyota";
    car2.model = "Camry";
    car2.year = 2018;

    std::cout << "Car 1: " << car1.brand << " " << car1.model << " " << car1.year << std::endl;
    std::cout << "Car 2: " << car2.brand << " " << car2.model << " " << car2.year << std::endl;

    // Section 4: Challenge Task - Student Structure
    std::cout << "\nSection 4: Challenge Task - Student Structure" << std::endl;
    struct Student {
        std::string name;
        int age;
        char grade;
    };

    Student s1;
    s1.name = "Liam";
    s1.age = 35;
    s1.grade = 'A';

    std::cout << "Name: " << s1.name << std::endl;
    std::cout << "Age: " << s1.age << std::endl;
    std::cout << "Grade: " << s1.grade << std::endl;

    return 0;
}
