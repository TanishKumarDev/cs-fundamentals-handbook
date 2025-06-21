// JavaScript let Keyword Demo
// Demonstrates all concepts from the GFG article on JavaScript let

// 1. Block Scope with let
{
  let blockVar = 2; // Block-scoped variable
  console.log("Inside block:", blockVar); // Output: 2
}
// console.log(blockVar); // Would throw ReferenceError: blockVar is not defined

// Contrast with var (global/function scope)
{
  var globalVar = 2; // Accessible outside block
  console.log("Inside block (var):", globalVar); // Output: 2
}
console.log("Outside block (var):", globalVar); // Output: 2

// 2. No Redeclaration in Same Scope
let userName = "John Doe"; // Initial declaration
userName = 0; // Reassignment is allowed
console.log("Reassigned let:", userName); // Output: 0
// let userName = 5; // Would throw SyntaxError: Identifier 'userName' has already been declared

// Contrast with var
var itemName = "Laptop"; // Initial declaration
var itemName = 0; // Redeclaration allowed
console.log("Redeclared var:", itemName); // Output: 0

// 3. Redeclaration in Different Blocks
let outerCounter = 10; // Outer scope
{
  let innerCounter = 2; // Inner scope, separate variable
  console.log("Inner block counter:", innerCounter); // Output: 2
}
console.log("Outer scope counter:", outerCounter); // Output: 10

// 4. Mixing var and let (demonstrating incompatibility)
var productId = 101; // Allowed
// let productId = 102; // Would throw SyntaxError
console.log("Product ID with var:", productId); // Output: 101

// 5. Hoisting with let (Temporal Dead Zone)
try {
  carModel = "Toyota"; // Access before declaration
  let carModel = "Honda";
} catch (e) {
  console.log("Hoisting error:", e.message); // Output: Cannot access 'carModel' before initialization
}

// Correct usage
let vehicleModel = "Volvo"; // Declare before use
console.log("Correct let usage:", vehicleModel); // Output: Volvo

// Contrast with var (hoisting allows use before declaration)
brandName = "BMW"; // Works due to hoisting
var brandName;
console.log("Hoisting with var:", brandName); // Output: BMW

// 6. Practical Example: Loop with let
for (let i = 0; i < 3; i++) {
  console.log("Loop iteration:", i); // Output: 0, 1, 2
}
// console.log(i); // Would throw ReferenceError: i is not defined

// 7. Shadowing Example
let totalPrice = 100; // Outer scope
{
  let totalPrice = 50; // Inner scope, shadows outer variable
  console.log("Inner totalPrice:", totalPrice); // Output: 50
}
console.log("Outer totalPrice:", totalPrice); // Output: 100