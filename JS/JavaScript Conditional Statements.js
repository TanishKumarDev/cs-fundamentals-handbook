// JavaScript Conditional Statements Demo
// Demonstrates all concepts related to JavaScript conditional statements with clear examples

// 1. if Statement
// Basic if statement
console.log("Basic if Statement:");
let age = 20;
if (age >= 18) {
    console.log("You are an adult"); // Output: You are an adult
}

// 2. if...else Statement
// if...else to check voting eligibility
console.log("\nif...else Statement:");
let votingAge = 16;
if (votingAge >= 18) {
    console.log("Eligible to vote");
} else {
    console.log("Not eligible to vote"); // Output: Not eligible to vote
}

// 3. if...else if...else Statement
// Check grade based on score
console.log("\nif...else if...else Statement:");
let score = 85;
if (score >= 90) {
    console.log("Grade: A");
} else if (score >= 80) {
    console.log("Grade: B"); // Output: Grade: B
} else if (score >= 70) {
    console.log("Grade: C");
} else {
    console.log("Grade: F");
}

// 4. Nested if Statements
// Check if a person can drive based on age and license
console.log("\nNested if Statements:");
let personAge = 25;
let hasLicense = true;
if (personAge >= 16) {
    if (hasLicense) {
        console.log("You can drive"); // Output: You can drive
    } else {
        console.log("You need a license to drive");
    }
} else {
    console.log("You are too young to drive");
}

// 5. switch Statement
// Determine day of the week
console.log("\nswitch Statement:");
let day = 3;
switch (day) {
    case 1:
        console.log("Monday");
        break;
    case 2:
        console.log("Tuesday");
        break;
    case 3:
        console.log("Wednesday"); // Output: Wednesday
        break;
    case 4:
        console.log("Thursday");
        break;
    case 5:
        console.log("Friday");
        break;
    default:
        console.log("Weekend or invalid day");
}

// switch with multiple cases
console.log("\nswitch with Multiple Cases:");
let fruit = "Apple";
switch (fruit.toLowerCase()) {
    case "apple":
    case "banana":
    case "orange":
        console.log(`${fruit} is a fruit`); // Output: Apple is a fruit
        break;
    default:
        console.log(`${fruit} is not recognized as a fruit`);
}

// 6. Ternary Operator
// Check if number is positive or negative
console.log("\nTernary Operator:");
let number = 10;
let result = number >= 0 ? "Positive" : "Negative";
console.log(`Number is ${result}`); // Output: Number is Positive

// Nested ternary operator
let temperature = 25;
let weather = temperature > 30 ? "Hot" : temperature > 15 ? "Warm" : "Cold";
console.log(`Weather is ${weather}`); // Output: Weather is Warm

// 7. Logical Operators in Conditionals
// Using && (AND)
console.log("\nLogical AND in if:");
let hasTicket = true;
let hasID = true;
if (hasTicket && hasID) {
    console.log("You can enter the event"); // Output: You can enter the event
} else {
    console.log("Entry denied");
}

// Using || (OR)
console.log("\nLogical OR in if:");
let isStudent = false;
let isSenior = true;
if (isStudent || isSenior) {
    console.log("You get a discount"); // Output: You get a discount
} else {
    console.log("No discount available");
}

// Using ! (NOT)
console.log("\nLogical NOT in if:");
let isRaining = false;
if (!isRaining) {
    console.log("You can go outside"); // Output: You can go outside
} else {
    console.log("Take an umbrella");
}

// 8. Practical Example: User Access Control
console.log("\nPractical Example: User Access Control:");
let userRole = "admin";
let isLoggedIn = true;
let accessLevel;

if (isLoggedIn) {
    switch (userRole) {
        case "admin":
            accessLevel = "Full access";
            break;
        case "editor":
            accessLevel = "Edit access";
            break;
        case "viewer":
            accessLevel = "View-only access";
            break;
        default:
            accessLevel = "No access";
    }
} else {
    accessLevel = "Please log in";
}
console.log(`User access: ${accessLevel}`); // Output: User access: Full access