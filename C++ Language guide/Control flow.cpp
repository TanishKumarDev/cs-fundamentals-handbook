// 1. if Statement
// 👉 Executes a block only if condition is true

int age = 20;

if (age >= 18) {
    cout << "You can vote." << endl;
}

// 2. if-else Statement
// 👉 Adds an alternative path if the condition is false.

int marks = 40;

if (marks >= 50) {
    cout << "Passed" << endl;
} else {
    cout << "Failed" << endl;
}

// 3. if-else-if Ladder
// 👉 Used to check multiple conditions one after another.
int marks = 85;

if (marks >= 90) {
    cout << "A Grade";
} else if (marks >= 75) {
    cout << "B Grade";
} else if (marks >= 60) {
    cout << "C Grade";
} else {
    cout << "Fail";
}

// 4. Nested if-else Statement
// 👉 if or if-else inside another if or else block 
int age = 20;
bool hasID = true;

if (age >= 18) {
    if (hasID) {
        cout << "Entry allowed.";
    } else {
        cout << "ID required.";
    }
} else {
    cout << "Underage. No entry.";
}

// 5. switch Statement
// 👉 Used when you want to match exact values
int day = 3;

switch (day) {
    case 1: cout << "Monday"; break;
    case 2: cout << "Tuesday"; break;
    case 3: cout << "Wednesday"; break;
    default: cout << "Invalid day";
}

// 6. for Loop
// 👉 Best when number of iterations is known
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
}

// 7. while Loop
// 👉 Best when number of iterations is unknown
int i = 1;

while (i <= 5) {
    cout << i << " ";
    i++;
}

// 8. do...while Loop
// 👉 Runs at least once regardless of condition
int i = 1;

do {
    cout << i << " ";
    i++;
} while (i <= 5);

// 9. break
// 👉 Exit loop or switch immediately
for (int i = 1; i <= 5; i++) {
    if (i == 3) break;
    cout << i << " ";
}

// 10. continue
// 👉 Skip current iteration, move to next
for (int i = 1; i <= 5; i++) {
    if (i == 3) continue;
    cout << i << " ";
}

// 11. return
// 👉 Exit function immediately
int add(int a, int b) {
    return a + b;
}

// 12. goto (⚠️ Avoid)
// 👉 Jump to a labeled block (but considered bad practice)
goto label;

cout << "This won't print";

label:
cout << "Jumped here";
