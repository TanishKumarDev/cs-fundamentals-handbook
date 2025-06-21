// JavaScript Data Types Demo
// Demonstrates all concepts from the GFG article on JavaScript Data Types

// 1. Number Type
const length = 16; // Integer
const weight = 7.5; // Decimal
const expLarge = 123e5; // Exponential: 12300000
const expSmall = 123e-5; // Exponential: 0.00123
console.log("Number types:", length, weight, expLarge, expSmall);
console.log("typeof number:", typeof weight); // Output: number
// Output: 16, 7.5, 12300000, 0.00123

// 2. String Type
const color = "Yellow"; // Double quotes
const lastName = 'Johnson'; // Single quotes
const mixedQuotes = "It's called 'Johnny'"; // Mixed quotes
console.log("String types:", color, lastName, mixedQuotes);
console.log("typeof string:", typeof color); // Output: string
// Output: Yellow, Johnson, It's called 'Johnny'

// 3. Boolean Type
const x = 5;
const y = 5;
const z = 6;
const isEqual = x == y; // true
const isNotEqual = x == z; // false
console.log("Boolean types:", isEqual, isNotEqual);
console.log("typeof boolean:", typeof isEqual); // Output: boolean
// Output: true, false

// 4. Object Type
const person = {firstName:"John", lastName:"Doe", age:50}; // Object
const cars = ["Saab", "Volvo", "BMW"]; // Array
const date = new Date("2022-03-25"); // Date
console.log("Object types:", person, cars, date);
console.log("typeof object:", typeof person, typeof cars, typeof date);
// Output: {firstName:"John", lastName:"Doe", age:50}, ["Saab", "Volvo", "BMW"], 2022-03-25T00:00:00.000Z
// Output: object, object, object

// 5. BigInt Type
const bigNum = BigInt("123456789012345678901234567890");
console.log("BigInt type:", bigNum);
console.log("typeof BigInt:", typeof bigNum); // Output: bigint
// Output: 123456789012345678901234567890n

// 6. Undefined Type
let undefinedVar; // undefined
console.log("Undefined type:", undefinedVar, typeof undefinedVar);
// Output: undefined, undefined
undefinedVar = undefined; // Explicitly undefined
console.log("Explicit undefined:", undefinedVar, typeof undefinedVar);
// Output: undefined, undefined

// 7. Null Type
let nullVar = null; // null
console.log("Null type:", nullVar, typeof nullVar); // Output: null, object

// 8. Symbol Type
const sym = Symbol("unique");
console.log("Symbol type:", sym, typeof sym); // Output: Symbol(unique), symbol

// 9. Dynamic Typing
let dynamic; // undefined
console.log("Dynamic (undefined):", dynamic, typeof dynamic);
// Output: undefined, undefined
dynamic = 42; // Number
console.log("Dynamic (number):", dynamic, typeof dynamic); // Output: 42, number
dynamic = "Hello"; // String
console.log("Dynamic (string):", dynamic, typeof dynamic); // Output: Hello, string

// 10. Type Coercion
const coercion1 = 16 + "Volvo"; // "16Volvo"
const coercion2 = 16 + 4 + "Volvo"; // "20Volvo"
const coercion3 = "Volvo" + 16 + 4; // "Volvo164"
console.log("Type coercion:", coercion1, coercion2, coercion3);
// Output: 16Volvo, 20Volvo, Volvo164

// 11. Empty Values
const emptyString = ""; // Empty string
console.log("Empty string:", emptyString, typeof emptyString);
// Output: "", string

// 12. Practical Example: User Profile
let userProfile; // undefined
userProfile ??= {name: "", isActive: false}; // Default object
userProfile.name ||= "Guest"; // Default name if falsy
userProfile.isActive &&= true; // Set to true if truthy
userProfile.id = BigInt("1000000000000000000"); // Large ID
userProfile.cars = ["Toyota"];
console.log("User profile:", userProfile);
// Output: {name:"Guest", isActive:false, id:1000000000000000000n, cars:["Toyota"]}