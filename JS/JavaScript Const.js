// JavaScript const Keyword Demo
// Demonstrates all concepts from the GFG article on JavaScript const

// 1. Basic const Declaration and Immutability
const PI_VALUE = 3.141592653589793; // Must be initialized
console.log("PI:", PI_VALUE); // Output: 3.141592653589793
// PI_VALUE = 3.14; // Would throw TypeError: Assignment to constant variable

// 2. Block Scope with const
const outerValue = 10; // Outer scope
{
  const innerValue = 2; // Inner scope, separate variable
  console.log("Inner block:", innerValue); // Output: 2
}
console.log("Outer scope:", outerValue); // Output: 10

// 3. Constant Arrays (Mutable Elements)
const vehicles = ["Saab", "Volvo", "BMW"]; // Constant reference
vehicles[0] = "Toyota"; // Allowed: modify element
vehicles.push("Audi"); // Allowed: add element
console.log("Modified array:", vehicles); // Output: ["Toyota", "Volvo", "BMW", "Audi"]
// vehicles = ["Honda", "Toyota"]; // Would throw TypeError

// 4. Constant Objects (Mutable Properties)
const vehicleInfo = {type:"Fiat", model:"500", color:"white"}; // Constant reference
vehicleInfo.color = "red"; // Allowed: modify property
vehicleInfo.owner = "Johnson"; // Allowed: add property
console.log("Modified object:", vehicleInfo); // Output: {type:"Fiat", model:"500", color:"red", owner:"Johnson"}
// vehicleInfo = {type:"Volvo"}; // Would throw TypeError

// 5. No Redeclaration in Same Scope
const maxAttempts = 3; // Initial declaration
// const maxAttempts = 5; // Would throw SyntaxError: Identifier 'maxAttempts' has already been declared
console.log("Max attempts:", maxAttempts); // Output: 3

// Mixing var/let with const
var itemCount = 10; // Allowed
// const itemCount = 20; // Would throw SyntaxError
console.log("Item count with var:", itemCount); // Output: 10

// 6. Redeclaration in Different Blocks
const score = 100; // Outer scope
{
  const score = 50; // Inner scope, separate variable
  console.log("Inner score:", score); // Output: 50
}
console.log("Outer score:", score); // Output: 100

// 7. Hoisting with const (Temporal Dead Zone)
try {
  console.log(brand); // ReferenceError: Cannot access 'brand' before initialization
  const brand = "Mercedes";
} catch (e) {
  console.log("Hoisting error:", e.message); // Output: Cannot access 'brand' before initialization
}

// Correct usage
const model = "Corolla"; // Declare before use
console.log("Correct const usage:", model); // Output: Corolla

// Contrast with var
product = "Phone"; // Works due to hoisting
var product;
console.log("Hoisting with var:", product); // Output: Phone

// 8. Practical Example: Configuration with const
const APP_CONFIG = {
  apiUrl: "https://api.example.com",
  maxRetries: 3
}; // Constant reference
APP_CONFIG.maxRetries = 5; // Allowed: modify property
console.log("Updated config:", APP_CONFIG); // Output: {apiUrl:"https://api.example.com", maxRetries:5}
// APP_CONFIG = {}; // Would throw TypeError

// 9. Function with const
const calculateArea = function(radius) {
  return PI_VALUE * radius * radius;
}; // Constant reference to function
console.log("Area of circle (radius 5):", calculateArea(5)); // Output: ~78.53981633974483
// calculateArea = () => 0; // Would throw TypeError