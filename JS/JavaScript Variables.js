// JavaScript Variables Demo
// Demonstrates all concepts from the GFG article on JavaScript Variables

// 1. Variable Declaration Methods
// Using let (block-scoped, reassignable)
let num1 = 5;
let num2 = 6;
let sum = num1 + num2; // Calculates 5 + 6 = 11
console.log("let example:", sum); // Output: 11

// Using const (block-scoped, immutable)
const fixedPrice1 = 10;
const fixedPrice2 = 20;
const totalPrice = fixedPrice1 + fixedPrice2; // Calculates 10 + 20 = 30
console.log("const example:", totalPrice); // Output: 30
// Note: fixedPrice1 = 15 would throw TypeError

// Using var (function-scoped, legacy)
var countA = 3;
var countB = 4;
var totalCount = countA + countB; // Calculates 3 + 4 = 7
console.log("var example:", totalCount); // Output: 7

// Automatic declaration (avoid in production)
autoVar = 100; // Implicit global (not recommended)
console.log("Automatic declaration:", autoVar); // Output: 100

// 2. Mixed Declaration Example
const itemPrice1 = 15;
const itemPrice2 = 25;
let cartTotal = itemPrice1 + itemPrice2; // Initial total: 40
console.log("Mixed const/let:", cartTotal); // Output: 40
cartTotal += 10; // Reassignable with let
console.log("Updated cartTotal:", cartTotal); // Output: 50

// 3. Identifiers
let userAge = 25; // Descriptive identifier
let $discount = 5; // Valid with $
let _counter = 10; // Valid with _
console.log("Identifiers:", userAge, $discount, _counter); // Output: 25, 5, 10

// 4. Assignment Operator
let score = 50;
score = score + 10; // Increments score by 10
console.log("Assignment operator:", score); // Output: 60

// 5. Data Types
const circlePi = 3.14; // Number
let userName = "Jane Doe"; // String
let response = 'Yes!'; // String
console.log("Data types:", circlePi, userName, response); // Output: 3.14, Jane Doe, Yes!

// 6. Declaring and Assigning
let vehicleName; // Declared, undefined
vehicleName = "Toyota"; // Assigned
let vehicleModel = "Camry"; // Declared and assigned
console.log("Declaring/Assigning:", vehicleName, vehicleModel); // Output: Toyota, Camry

// 7. Multiple Variables in One Statement
let customer = "John Smith", vehicle = "Honda", cost = 300;
console.log("Multiple declarations:", customer, vehicle, cost); // Output: John Smith, Honda, 300

// 8. Undefined Variables
let unassignedVar;
console.log("Undefined variable:", unassignedVar); // Output: undefined

// 9. Re-Declaring Variables
var brandName = "BMW";
var brandName; // Value persists
console.log("Re-declaring with var:", brandName); // Output: BMW

// 10. Arithmetic and String Concatenation
let calc1 = 5 + 2 + 3; // Number addition: 10
let calc2 = "John" + " " + "Smith"; // String concatenation: John Smith
let calc3 = "5" + 2 + 3; // String + numbers: 523
let calc4 = 2 + 3 + "5"; // Numbers + string: 55
console.log("Arithmetic/Concatenation:", calc1, calc2, calc3, calc4);
// Output: 10, John Smith, 523, 55

// 11. Dollar Sign and Underscore
let $message = "Hello World";
let $$$ = 3;
let $totalMoney = 50;
let _userLastName = "Wilson";
let _index = 1;
let _100items = 10;
console.log("Dollar/Underscore:", $message, $$$, $totalMoney, _userLastName, _index, _100items);
// Output: Hello World, 3, 50, Wilson, 1, 10
