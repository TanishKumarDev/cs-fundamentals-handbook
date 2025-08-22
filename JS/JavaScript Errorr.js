// JavaScript Error Handling Demo
// Demonstrates all concepts related to JavaScript error handling with clear examples

// 1. Basic try...catch
// Handling a simple error
console.log("Basic try...catch:");
try {
    let result = undefinedVariable; // ReferenceError: undefinedVariable is not defined
    console.log(result);
} catch (error) {
    console.log("Error caught:", error.message); // Output: Error caught: undefinedVariable is not defined
}

// 2. try...catch with finally
// Using finally to execute code regardless of error
console.log("\ntry...catch with finally:");
try {
    let num = "abc";
    if (isNaN(num)) {
        throw new Error("Not a number");
    }
    console.log(num * 2);
} catch (error) {
    console.log("Error caught:", error.message); // Output: Error caught: Not a number
} finally {
    console.log("This runs regardless of error"); // Output: This runs regardless of error
}

// 3. Throwing Custom Errors
// Throwing a custom error with specific message
console.log("\nThrowing Custom Errors:");
try {
    let age = -5;
    if (age < 0) {
        throw new Error("Age cannot be negative");
    }
    console.log("Age is valid:", age);
} catch (error) {
    console.log("Custom error:", error.message); // Output: Custom error: Age cannot be negative
}

// 4. Handling Specific Error Types
// Differentiating between error types
console.log("\nHandling Specific Error Types:");
try {
    let jsonString = '{"name": "Alice", "age": 25'; // Invalid JSON
    let obj = JSON.parse(jsonString); // SyntaxError: Unexpected end of JSON input
    console.log(obj);
} catch (error) {
    if (error instanceof SyntaxError) {
        console.log("Syntax Error caught:", error.message); // Output: Syntax Error caught: Unexpected end of JSON input
    } else {
        console.log("Other error:", error.message);
    }
}

// 5. try...catch with Nested Errors
// Handling errors in nested try blocks
console.log("\nNested try...catch:");
try {
    try {
        let value = null;
        value.toUpperCase(); // TypeError: Cannot read properties of null
    } catch (innerError) {
        throw new Error("Inner error occurred: " + innerError.message);
    }
} catch (outerError) {
    console.log("Outer error caught:", outerError.message); // Output: Outer error caught: Inner error occurred: Cannot read properties of null
}

// 6. Error Object Properties
// Exploring error object properties
console.log("\nError Object Properties:");
try {
    let arr = [];
    arr[10].toString(); // TypeError: Cannot read properties of undefined
} catch (error) {
    console.log("Error name:", error.name); // Output: Error name: TypeError
    console.log("Error message:", error.message); // Output: Error message: Cannot read properties of undefined
    console.log("Error stack:", error.stack); // Output: Error stack: (stack trace)
}

// 7. Custom Error Classes
// Defining and using a custom error class
console.log("\nCustom Error Class:");
class ValidationError extends Error {
    constructor(message) {
        super(message);
        this.name = "ValidationError";
    }
}
try {
    let username = "";
    if (!username) {
        throw new ValidationError("Username cannot be empty");
    }
    console.log("Username:", username);
} catch (error) {
    if (error instanceof ValidationError) {
        console.log(`${error.name}: ${error.message}`); // Output: ValidationError: Username cannot be empty
    } else {
        console.log("Other error:", error.message);
    }
}

// 8. Practical Example: Form Validation
// Simulating form input validation
console.log("\nPractical Example: Form Validation:");
function validateForm(email, password) {
    try {
        if (!email.includes("@")) {
            throw new Error("Invalid email format");
        }
        if (password.length < 6) {
            throw new Error("Password must be at least 6 characters");
        }
        console.log("Form validated successfully!");
        return true;
    } catch (error) {
        console.log("Validation error:", error.message);
        return false;
    } finally {
        console.log("Form validation attempt completed");
    }
}
console.log("Test 1:");
validateForm("invalid-email", "123"); // Output: Validation error: Invalid email format, Form validation attempt completed
console.log("\nTest 2:");
validateForm("test@example.com", "secure123"); // Output: Form validated successfully!, Form validation attempt completed