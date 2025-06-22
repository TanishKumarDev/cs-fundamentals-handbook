#include <iostream>
#include <string>
using namespace std;

// 1. While Loop
void demoWhileLoop() {
    int i = 0;
    while (i < 5) {
        cout << i << " ";
        i++;
    }
    cout << endl;
}

// 2. Countdown While
void demoCountdownWhile() {
    int countdown = 3;
    while (countdown > 0) {
        cout << countdown << " ";
        countdown--;
    }
    cout << "Happy New Year!" << endl;
}

// 3. Do-While Loop
void demoDoWhileLoop() {
    int i = 0;
    do {
        cout << i << " ";
        i++;
    } while (i < 5);
    cout << endl;
}

// 4. Do-While with False Condition
void demoDoWhileFalse() {
    int i = 10;
    do {
        cout << "i is " << i << endl;
    } while (i < 5);
}

// 5. Fixed: User Input
void demoUserInput() {
    int number;
    int attempts = 0;
    const int MAX_ATTEMPTS = 5;

    cout << "(You can enter up to " << MAX_ATTEMPTS << " numbers)" << endl;
    do {
        cout << "Enter a positive number: ";
        cin >> number;
        attempts++;
    } while (number > 0 && attempts < MAX_ATTEMPTS);

    if (attempts >= MAX_ATTEMPTS) {
        cout << "Max attempts reached. Exiting input loop." << endl;
    }
}

// 6. Even Numbers While
void demoEvenNumbersWhile() {
    int i = 0;
    while (i <= 10) {
        cout << i << " ";
        i += 2;
    }
    cout << endl;
}

// 7. Reverse Numbers
void demoReverseNumbers() {
    int number = 12345, reversed = 0;
    while (number) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    cout << "Reversed: " << reversed << endl;
}

// 8. Yatzy Game
void demoYatzyGame() {
    for (int dice = 1; dice <= 6; dice++) {
        if (dice == 6)
            cout << "Yatzy!" << endl;
        else
            cout << "No Yatzy" << endl;
    }
}

// 9. For Loop
void demoForLoop() {
    for (int i = 0; i < 5; i++)
        cout << i << " ";
    cout << endl;
}

// 10. Even Numbers For
void demoEvenNumbersFor() {
    for (int i = 0; i <= 10; i += 2)
        cout << i << " ";
    cout << endl;
}

// 11. Odd Numbers For
void demoOddNumbers() {
    for (int i = 1; i <= 10; i += 2)
        cout << i << " ";
    cout << endl;
}

// 12. Sum Numbers
void demoSumNumbers() {
    int sum = 0;
    for (int i = 1; i <= 5; i++)
        sum += i;
    cout << "Sum: " << sum << endl;
}

// 13. Countdown For
void demoCountdownFor() {
    for (int i = 5; i > 0; i--)
        cout << i << " ";
    cout << endl;
}

// 14. Powers of Two
void demoPowersOfTwo() {
    for (int i = 2; i <= 512; i *= 2)
        cout << i << " ";
    cout << endl;
}

// 15. Multiplication Table
void demoMultiplicationTable() {
    int num = 2;
    for (int i = 1; i <= 10; i++)
        cout << num << " x " << i << " = " << num * i << endl;
}

// 16. Nested Loops
void demoNestedLoops() {
    for (int i = 1; i <= 2; i++) {
        cout << "Outer: " << i << endl;
        for (int j = 1; j <= 3; j++)
            cout << " Inner: " << j << endl;
    }
}

// 17. Nested Multiplication Table
void demoNestedMultiplicationTable() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++)
            cout << i * j << " ";
        cout << endl;
    }
}

// 18. For-Each Array
void demoForEachArray() {
    int arr[] = {10, 20, 30, 40, 50};
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// 19. For-Each String
void demoForEachString() {
    string word = "Hello";
    for (char c : word)
        cout << c << " ";
    cout << endl;
}

// 20. Count by Tens
void demoCountByTens() {
    for (int i = 0; i <= 100; i += 10)
        cout << i << " ";
    cout << endl;
}

// MAIN
int main() {
    cout << "=== C++ Loops Demonstration ===" << endl;

    cout << "\n1. While Loop:" << endl;
    demoWhileLoop();

    cout << "\n2. Countdown with While Loop:" << endl;
    demoCountdownWhile();

    cout << "\n3. Do-While Loop:" << endl;
    demoDoWhileLoop();

    cout << "\n4. Do-While with False Condition:" << endl;
    demoDoWhileFalse();

    cout << "\n5. User Input with Do-While:" << endl;
    demoUserInput();

    cout << "\n6. Even Numbers with While Loop:" << endl;
    demoEvenNumbersWhile();

    cout << "\n7. Reverse Numbers with While Loop:" << endl;
    demoReverseNumbers();

    cout << "\n8. Yatzy Game with While and If-Else:" << endl;
    demoYatzyGame();

    cout << "\n9. For Loop:" << endl;
    demoForLoop();

    cout << "\n10. Even Numbers with For Loop:" << endl;
    demoEvenNumbersFor();

    cout << "\n11. Odd Numbers with For Loop:" << endl;
    demoOddNumbers();

    cout << "\n12. Sum of Numbers with For Loop:" << endl;
    demoSumNumbers();

    cout << "\n13. Countdown with For Loop:" << endl;
    demoCountdownFor();

    cout << "\n14. Powers of 2 with For Loop:" << endl;
    demoPowersOfTwo();

    cout << "\n15. Multiplication Table with For Loop:" << endl;
    demoMultiplicationTable();

    cout << "\n16. Nested Loops:" << endl;
    demoNestedLoops();

    cout << "\n17. Multiplication Table with Nested Loops:" << endl;
    demoNestedMultiplicationTable();

    cout << "\n18. For-Each Loop with Array:" << endl;
    demoForEachArray();

    cout << "\n19. For-Each Loop with String:" << endl;
    demoForEachString();

    cout << "\n20. Count by Tens with For Loop:" << endl;
    demoCountByTens();

    return 0;
}
