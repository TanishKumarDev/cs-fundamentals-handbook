#include <iostream>
#include <string>

int main() {
    // Section 1: Array Declaration and Initialization
    std::cout << "Section 1: Array Declaration and Initialization" << std::endl;
    std::string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
    int myNum[3] = {10, 20, 30};
    std::cout << "First car: " << cars[0] << std::endl;
    std::cout << "First number: " << myNum[0] << std::endl;

    // Section 2: Changing Array Elements
    std::cout << "\nSection 2: Changing Array Elements" << std::endl;
    cars[0] = "Opel";
    std::cout << "Updated car: " << cars[0] << std::endl;

    // Section 3: For Loop with Arrays
    std::cout << "\nSection 3: For Loop with Arrays" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << i << " = " << cars[i] << std::endl;
    }

    // Section 4: Foreach Loop
    std::cout << "\nSection 4: Foreach Loop" << std::endl;
    for (int num : myNum) {
        std::cout << num << std::endl;
    }

    // Section 5: Array Size with sizeof
    std::cout << "\nSection 5: Array Size with sizeof" << std::endl;
    int numbers[5] = {10, 20, 30, 40, 50};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    std::cout << "Array length: " << length << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << numbers[i] << std::endl;
    }

    // Section 6: Average of Ages
    std::cout << "\nSection 6: Average of Ages" << std::endl;
    int ages[8] = {20, 22, 18, 35, 48, 26, 87, 70};
    float sum = 0;
    for (int age : ages) {
        sum += age;
    }
    float avg = sum / (sizeof(ages) / sizeof(ages[0]));
    std::cout << "The average age is: " << avg << std::endl;

    // Section 7: Lowest Age
    std::cout << "\nSection 7: Lowest Age" << std::endl;
    int lowestAge = ages[0];
    for (int age : ages) {
        if (lowestAge > age) {
            lowestAge = age;
        }
    }
    std::cout << "The lowest age is: " << lowestAge << std::endl;

    // Section 8: Multi-Dimensional Array
    std::cout << "\nSection 8: Multi-Dimensional Array" << std::endl;
    std::string letters[2][4] = {
        {"A", "B", "C", "D"},
        {"E", "F", "G", "H"}
    };
    letters[0][0] = "Z";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << letters[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
