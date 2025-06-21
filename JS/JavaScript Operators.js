// JavaScript Operators Demo
// Demonstrates all concepts from the GFG article on JavaScript Operators

// 1. Assignment Operators
let assignX = 10; // Basic assignment
let assignY = 2; // Basic assignment
let assignZ = assignX + assignY; // Assign sum: 10 + 2 = 12
assignX += 5; // Addition assignment: 10 + 5 = 15
console.log("Assignment operators:", assignX, assignY, assignZ); // Output: 15, 2, 12

// 2. Arithmetic Operators
const multiplier = 3;
let arithResult = (100 + 50) * multiplier; // (150) * 3 = 450
let increment = 5;
increment++; // Increment: 5 + 1 = 6
let modulus = 10 % 3; // Remainder: 10 % 3 = 1
console.log("Arithmetic operators:", arithResult, increment, modulus); // Output: 450, 6, 1

// 3. Comparison Operators
let compX = 5;
let compY = 2;
let isGreater = compX > compY; // 5 > 2 = true
let strictEqual = compX === "5"; // 5 === "5" = false (different types)
console.log("Comparison operators:", isGreater, strictEqual); // Output: true, false

// 4. String Comparison
let textA = "A";
let textB = "B";
let stringComp = textA < textB; // Alphabetical: A < B = true
let numTextA = "20";
let numTextB = "5";
let numStringComp = numTextA < numTextB; // Alphabetical: "2" < "5" = true
console.log("String comparison:", stringComp, numStringComp); // Output: true, true

// 5. String Operators (Concatenation)
let firstName = "John";
let lastName = "Doe";
let fullName = firstName + " " + lastName; // Concatenate: "John Doe"
let greeting = "What a very ";
greeting += "nice day"; // Append: "What a very nice day"
console.log("String operators:", fullName, greeting); // Output: John Doe, What a very nice day

// 6. String and Number Concatenation
let numAdd = 5 + 5; // Number addition: 10
let strNumAdd = "5" + 5; // Concatenation: "55"
let strAdd = "Hello" + 5; // Concatenation: "Hello5"
console.log("String and number:", numAdd, strNumAdd, strAdd); // Output: 10, 55, Hello5

// 7. Logical Operators
let logicX = 5;
let logicY = 10;
let logicResult = (logicX > 0 && logicY < 20); // true && true = true
let notResult = !(logicX > logicY); // !(5 > 10) = !false = true
console.log("Logical operators:", logicResult, notResult); // Output: true, true

// 8. Type Operators
let typeNum = 42;
let typeArr = [1, 2, 3];
let typeCheck = typeof typeNum; // "number"
let instanceCheck = typeArr instanceof Array; // true
console.log("Type operators:", typeCheck, instanceCheck); // Output: number, true

// 9. Bitwise Operators
let bitResult = 5 & 1; // 0101 & 0001 = 0001 = 1
let bitOr = 5 | 1; // 0101 | 0001 = 0101 = 5
let bitNot = ~5; // ~0101 (32-bit) = 111...1010 = -6
console.log("Bitwise operators:", bitResult, bitOr, bitNot); // Output: 1, 5, -6

// 10. Practical Example: Shopping Cart Calculation
const itemPrice = 20;
let quantity = 3;
quantity *= 2; // Update quantity: 3 * 2 = 6
const hasDiscount = itemPrice > 10 && quantity >= 5; // true
const totalCost = itemPrice * quantity; // 20 * 6 = 120
console.log("Shopping cart:", { itemPrice, quantity, hasDiscount, totalCost });
// Output: { itemPrice: 20, quantity: 6, hasDiscount: true, totalCost: 120 }