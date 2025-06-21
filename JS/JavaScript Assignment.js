// JavaScript Assignment Operators Demo
// Demonstrates all concepts from the GFG article on JavaScript Assignment Operators

// 1. Simple Assignment Operator
let simpleX = 10; // Initialize
let simpleY = 5; // Initialize
simpleX = 10 + simpleY; // Assign sum: 10 + 5 = 15
console.log("Simple assignment:", simpleX); // Output: 15

// 2. Arithmetic Assignment Operators
// Addition Assignment
let addX = 10;
addX += 5; // 10 + 5 = 15
let text = "Hello";
text += " World"; // "Hello World"
console.log("Addition assignment:", addX, text); // Output: 15, Hello World

// Subtraction Assignment
let subX = 10;
subX -= 5; // 10 - 5 = 5
console.log("Subtraction assignment:", subX); // Output: 5

// Multiplication Assignment
let mulX = 10;
mulX *= 5; // 10 * 5 = 50
console.log("Multiplication assignment:", mulX); // Output: 50

// Division Assignment
let divX = 10;
divX /= 5; // 10 / 5 = 2
console.log("Division assignment:", divX); // Output: 2

// Modulus Assignment
let modX = 10;
modX %= 5; // 10 % 5 = 0
console.log("Modulus assignment:", modX); // Output: 0

// Exponentiation Assignment
let expX = 10;
expX **= 5; // 10^5 = 100000
console.log("Exponentiation assignment:", expX); // Output: 100000

// 3. Shift Assignment Operators
// Left Shift Assignment
let leftShiftX = -100; // 11111111111111111111111110011100
leftShiftX <<= 5; // Shift left: ...11001110000000 = -3200
console.log("Left shift assignment:", leftShiftX); // Output: -3200

// Right Shift Assignment
let rightShiftX = -100; // 11111111111111111111111110011100
rightShiftX >>= 5; // Shift right (signed): ...11111100 = -4
console.log("Right shift assignment:", rightShiftX); // Output: -4

// Unsigned Right Shift Assignment
let unsignedShiftX = -100; // 11111111111111111111111110011100
unsignedShiftX >>>= 5; // Shift right (unsigned): ...11100111 = 134217724
console.log("Unsigned right shift assignment:", unsignedShiftX); // Output: 134217724

// 4. Bitwise Assignment Operators
// Bitwise AND Assignment
let bitAndX = 10; // 1010
bitAndX &= 5; // 0101 & 1010 = 0000 = 0
console.log("Bitwise AND assignment:", bitAndX); // Output: 0

// Bitwise OR Assignment
let bitOrX = 10; // 1010
bitOrX |= 5; // 0101 | 1010 = 1111 = 15
console.log("Bitwise OR assignment:", bitOrX); // Output: 15

// Bitwise XOR Assignment
let bitXorX = 10; // 1010
bitXorX ^= 5; // 0101 ^ 1010 = 1111 = 15
console.log("Bitwise XOR assignment:", bitXorX); // Output: 15

// 5. Logical Assignment Operators (ES2020)
// Logical AND Assignment
let andX = 10; // Truthy
andX &&= 5; // Assign 5 since 10 is truthy
console.log("Logical AND assignment:", andX); // Output: 5
let andY = 0; // Falsy
andY &&= 5; // No assignment since 0 is falsy
console.log("Logical AND with falsy:", andY); // Output: 0

// Logical OR Assignment
let orX = 10; // Truthy
orX ||= 5; // No assignment since 10 is truthy
console.log("Logical OR assignment:", orX); // Output: 10
let orY = 0; // Falsy
orY ||= 5; // Assign 5 since 0 is falsy
console.log("Logical OR with falsy:", orY); // Output: 5

// Nullish Coalescing Assignment
let nullishX; // undefined
nullishX ??= 5; // Assign 5 since undefined
console.log("Nullish coalescing assignment:", nullishX); // Output: 5
let nullishY = 0; // Not null/undefined
nullishY ??= 5; // No assignment since 0 is not null
console.log("Nullish with non-null:", nullishY); // Output: 0

// 6. Practical Example: User Score Tracking
let score = 100; // Initial score
score += 50; // Add points: 100 + 50 = 150
score *= 2; // Double score: 150 * 2 = 300
score %= 200; // Cap score: 300 % 200 = 100
score &&= score >= 50 ? 75 : 25; // Set to 75 if score >= 50
score ||= 10; // Ensure minimum score of 10
score ??= 50; // Ensure not null/undefined
console.log("User score:", score); // Output: 75