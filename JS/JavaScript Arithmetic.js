// JavaScript Arithmetic Operators Demo
// Demonstrates all concepts from the GFG article on JavaScript Arithmetic

// 1. Arithmetic Operations (Literals, Variables, Expressions)
const factor = 3;
const addend = 10;
let literalSum = 100 + 50; // Literals: 150
let variableSum = factor + addend; // Variables: 3 + 10 = 13
let expressionResult = (100 + 50) * factor; // Expression: (150) * 3 = 450
console.log("Arithmetic operations:", literalSum, variableSum, expressionResult);
// Output: 150, 13, 450

// 2. Addition Operator
let addX = 5;
let addY = 2;
let addResult = addX + addY; // 5 + 2 = 7
console.log("Addition:", addResult); // Output: 7

// 3. Subtraction Operator
let subX = 5;
let subY = 2;
let subResult = subX - subY; // 5 - 2 = 3
console.log("Subtraction:", subResult); // Output: 3

// 4. Multiplication Operator
let mulX = 5;
let mulY = 2;
let mulResult = mulX * mulY; // 5 * 2 = 10
console.log("Multiplication:", mulResult); // Output: 10

// 5. Division Operator
let divX = 5;
let divY = 2;
let divResult = divX / divY; // 5 / 2 = 2.5
console.log("Division:", divResult); // Output: 2.5

// 6. Modulus Operator
let modX = 5;
let modY = 2;
let modResult = modX % modY; // 5 % 2 = 1
console.log("Modulus:", modResult); // Output: 1

// 7. Increment Operator
let incX = 5;
incX++; // 5 + 1 = 6
let incResult = incX;
console.log("Increment:", incResult); // Output: 6

// 8. Decrement Operator
let decX = 5;
decX--; // 5 - 1 = 4
let decResult = decX;
console.log("Decrement:", decResult); // Output: 4

// 9. Exponentiation Operator
let expX = 5;
let expResult = expX ** 2; // 5^2 = 25
let powResult = Math.pow(expX, 2); // Equivalent: 25
console.log("Exponentiation:", expResult, powResult); // Output: 25, 25

// 10. Operator Precedence
let precX = 100 + 50 * 3; // 100 + (50 * 3) = 250
let precY = (100 + 50) * 3; // (150) * 3 = 450
let precZ = 100 + 50 - 3; // (100 + 50) - 3 = 147
let precW = 100 / 50 * 3; // (100 / 50) * 3 = 6
console.log("Operator precedence:", precX, precY, precZ, precW);
// Output: 250, 450, 147, 6

// 11. Practical Example: Shopping Cart Calculation
const unitPrice = 20;
let quantity = 3;
const taxRate = 0.1; // 10%
let subtotal = unitPrice * quantity; // 20 * 3 = 60
subtotal += subtotal * taxRate; // 60 + (60 * 0.1) = 66
quantity++; // Increment quantity: 4
let isEvenQuantity = quantity % 2 === 0; // 4 % 2 = 0 (true)
console.log("Shopping cart:", { unitPrice, quantity, subtotal, isEvenQuantity });
// Output: { unitPrice: 20, quantity: 4, subtotal: 66, isEvenQuantity: true }