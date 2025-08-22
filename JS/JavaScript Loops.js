// JavaScript Loops Demo
// Demonstrates all concepts related to JavaScript loops with clear examples

// 1. for Loop
// Basic for loop to iterate 5 times
console.log("Basic for Loop:");
for (let i = 0; i < 5; i++) {
    console.log(`Iteration ${i}: ${i * 2}`); // Output: 0, 2, 4, 6, 8
}

// for loop with array
let fruits = ["Apple", "Banana", "Orange"];
console.log("\nfor Loop with Array:");
for (let i = 0; i < fruits.length; i++) {
    console.log(`Fruit ${i + 1}: ${fruits[i]}`); // Output: Apple, Banana, Orange
}

// 2. while Loop
// Basic while loop to count down from 5
console.log("\nBasic while Loop:");
let count = 5;
while (count > 0) {
    console.log(`Count: ${count}`); // Output: 5, 4, 3, 2, 1
    count--;
}

// while loop with condition
let num = 1;
console.log("\nwhile Loop with Condition:");
while (num <= 10) {
    if (num % 2 === 0) {
        console.log(`Even number: ${num}`); // Output: 2, 4, 6, 8, 10
    }
    num++;
}

// 3. do...while Loop
// Basic do...while loop
console.log("\nBasic do...while Loop:");
let j = 0;
do {
    console.log(`Value: ${j}`); // Output: 0, 1, 2, 3, 4
    j++;
} while (j < 5);

// do...while with guaranteed execution
let input = 0;
console.log("\ndo...while with Input Check:");
do {
    console.log(`Input value: ${input}`); // Executes at least once
    input--;
} while (input > 0); // Output: 0 (runs once since condition is false)

// 4. for...in Loop
// Iterating over object properties
console.log("\nfor...in Loop with Object:");
let person = { name: "Alice", age: 25, city: "New York" };
for (let key in person) {
    console.log(`${key}: ${person[key]}`); // Output: name: Alice, age: 25, city: New York
}

// for...in with array (not recommended for arrays)
let colors = ["Red", "Green", "Blue"];
console.log("\nfor...in with Array:");
for (let index in colors) {
    console.log(`Index ${index}: ${colors[index]}`); // Output: Index 0: Red, Index 1: Green, Index 2: Blue
}

// 5. for...of Loop
// Iterating over array elements
console.log("\nfor...of Loop with Array:");
for (let color of colors) {
    console.log(`Color: ${color}`); // Output: Red, Green, Blue
}

// for...of with string
let str = "Hello";
console.log("\nfor...of Loop with String:");
for (let char of str) {
    console.log(`Character: ${char}`); // Output: H, e, l, l, o
}

// 6. Nested Loops
// Creating a multiplication table
console.log("\nNested for Loops (Multiplication Table):");
for (let i = 1; i <= 3; i++) {
    for (let j = 1; j <= 3; j++) {
        console.log(`${i} * ${j} = ${i * j}`); // Output: 1*1=1, 1*2=2, ..., 3*3=9
    }
}

// 7. Loop Control Statements
// break: Exit loop early
console.log("\nfor Loop with break:");
for (let i = 0; i < 10; i++) {
    if (i === 5) break;
    console.log(`Value: ${i}`); // Output: 0, 1, 2, 3, 4
}

// continue: Skip to next iteration
console.log("\nfor Loop with continue:");
for (let i = 0; i < 5; i++) {
    if (i % 2 === 0) continue;
    console.log(`Odd value: ${i}`); // Output: 1, 3
}

// 8. Practical Example: Sum of Even Numbers
console.log("\nPractical Example: Sum of Even Numbers:");
let numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let sum = 0;
for (let num of numbers) {
    if (num % 2 === 0) {
        sum += num;
    }
}
console.log(`Sum of even numbers: ${sum}`); // Output: 30 (2 + 4 + 6 + 8 + 10)