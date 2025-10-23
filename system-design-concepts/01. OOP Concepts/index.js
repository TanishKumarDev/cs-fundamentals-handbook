console.log("⭐ Classes and Objects in OOP")

// Class definition
class Student {
    constructor(name, age) {
        this.name = name;
        this.age = age;
    }

    takeExam() {
        console.log(`${this.name} is taking an exam.`);
    }

    takeLeave(){
        console.log(`${this.name} is taking leave.`);
    }
}

// Object instantiation
const studentA = new Student("Alice", 20);
studentA.takeExam();  // Output: Alice is taking an exam.
studentA.takeLeave(); // Output: Alice is taking leave.

// Another object instantiation
const studentB = new Student("Bob", 22);
studentB.takeExam();
studentB.takeLeave();

// Encapsulation in OOP
console.log("⭐ Encapsulation in OOP")
class Employee {
    constructor() {
        this.id = null;
        this.name = null;
    }

    setId(id) {
        this.id = id;
    }

    setName(name) {
        this.name = name;
    }

    getId() {
        return this.id;
    }

    getName() {
        return this.name;
    }
}

const emp = new Employee();

// Using setters
emp.setId(101);
emp.setName('Geek');

// Using getters
console.log('Employee ID: ' + emp.getId());
console.log('Employee Name: ' + emp.getName());

// Abstraction In OOP
console.log("⭐ Abstraction In OOP")
class Vehicle {
    constructor(){
        if(this.constructor === Vehicle){
            throw new Error("Abstract classes can't be instantiated.");
        }
    }

    // abstract method
    accelerarate(){
        throw new Error("Method 'accelerarate()' must be implemented.");
    }

    brake(){
        console.log("The vehicle is braking.");
    }

    // concrete method
    startEngine(){  
        console.log("The engine has started.");
    }
   
}

class Car extends Vehicle {
    accelerarate(){
        console.log("The car is accelerating.");
    }

    brake(){
        console.log("The car is braking.");
    }
}

const myCar = new Car();
myCar.startEngine();
myCar.accelerarate();
myCar.brake();

// Inheritance in OOP
console.log("⭐ Inheritance in OOP")
// Superclass (Parent)
class Animal {
    eat() {
        console.log('Animal is eating...');
    }

    sleep() {
        console.log('Animal is sleeping...');
    }
}

// Subclass (Child) - Inherits from Animal
class Dog extends Animal {
    bark() {
        console.log('Dog is barking!');
    }
}

// Main
const myDog = new Dog();

// Inherited methods (from Animal)
myDog.eat();
myDog.sleep();

// Child class method
myDog.bark();

// Polymorphism in OOP
console.log("⭐ Polymorphism in OOP")
class Calculator {
    // Method for adding two integers
    add(a, b) {
        return a + b;
    }

    // Overloaded method for adding three integers
    add(a, b, c) {
        if (arguments.length === 3) {
            return a + b + c;
        }
        return this.add(a, b);
    }

    // Overloaded method for adding two doubles
    add(a, b) {
        if (typeof a === 'number' && typeof b === 'number') {
            return a + b;
        }
        return this.add(a, b);
    }
}

const myCalculator = new Calculator();

// Example usage of the overloaded methods
const sum1 = myCalculator.add(5, 3);
const sum2 = myCalculator.add(4, 6, 2);
const sum3 = myCalculator.add(3.5, 2.7);

// Output the results
console.log('Sum of 5 and 3:', sum1);
console.log('Sum of 4, 6, and 2:', sum2);
console.log('Sum of 3.5 and 2.7:', sum3);
