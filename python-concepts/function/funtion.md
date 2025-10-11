# Python Basics: Functions, Pass Statement, and Global/Local Variables

## 1. Python Functions

### 1.1 Overview
- Functions are reusable blocks of code that perform specific tasks, defined using the `def` keyword.
- Syntax:
  ```python
  def function_name(parameters):
      # function body
  ```

### 1.2 Defining and Calling a Function
- Use `def` to define, call by function name with `()`.

#### Example:
```python
def fun():
    print("Welcome to GFG")

fun()  # Call the function
```
#### Output:
```
Welcome to GFG
```

### 1.3 Function Arguments
- Values passed to functions, optional or required.
- Syntax with return:
  ```python
  def function_name(parameters):
      """Docstring"""
      # body
      return expression
  ```

#### Example:
```python
def evenOdd(x):
    if (x % 2 == 0):
        return "Even"
    else:
        return "Odd"

print(evenOdd(16))
print(evenOdd(7))
```
#### Output:
```
Even
Odd
```

### 1.4 Types of Function Arguments
- **Default Arguments**: Assumes a value if not provided.
  ```python
  def myFun(x, y=50):
      print("x:", x)
      print("y:", y)

  myFun(10)
  ```
  #### Output:
  ```
  x: 10
  y: 50
  ```

- **Keyword Arguments**: Order doesn’t matter if names are specified.
  ```python
  def student(fname, lname):
      print(fname, lname)

  student(fname='Geeks', lname='Practice')
  student(lname='Practice', fname='Geeks')
  ```
  #### Output:
  ```
  Geeks Practice
  Geeks Practice
  ```

- **Positional Arguments**: Assigned by order.
  ```python
  def nameAge(name, age):
      print("Hi, I am", name)
      print("My age is", age)

  nameAge("Suraj", 27)
  nameAge(27, "Suraj")
  ```
  #### Output:
  ```
  Case-1:
  Hi, I am Suraj
  My age is 27

  Case-2:
  Hi, I am 27
  My age is Suraj
  ```

- **Arbitrary Arguments**: Variable number of arguments using `*args` (non-keyword) and `**kwargs` (keyword).
  ```python
  def myFun(*args, **kwargs):
      print("Non-Keyword Arguments (*args):")
      for arg in args:
          print(arg)
      print("\nKeyword Arguments (**kwargs):")
      for key, value in kwargs.items():
          print(f"{key} == {value}")

  myFun('Hey', 'Welcome', first='Geeks', mid='for', last='Geeks')
  ```
  #### Output:
  ```
  Non-Keyword Arguments (*args):
  Hey
  Welcome

  Keyword Arguments (**kwargs):
  first == Geeks
  mid == for
  last == Geeks
  ```

### 1.5 Function within Functions
- Inner functions (nested) can access outer scope variables.
  ```python
  def f1():
      s = 'I love GeeksforGeeks'
      def f2():
          print(s)
      f2()

  f1()
  ```
  #### Output:
  ```
  I love GeeksforGeeks
  ```

### 1.6 Anonymous Functions
- Defined using `lambda`, no name.
  ```python
  def cube(x): return x*x*x   # Without lambda
  cube_l = lambda x: x*x*x    # With lambda

  print(cube(7))
  print(cube_l(7))
  ```
  #### Output:
  ```
  343
  343
  ```

### 1.7 Return Statement
- Ends function and returns a value.
  ```python
  def square_value(num):
      """This function returns the square value of the entered number"""
      return num**2

  print(square_value(2))
  print(square_value(-4))
  ```
  #### Output:
  ```
  4
  16
  ```

### 1.8 Pass by Reference and Pass by Value
- Python uses "pass-by-object-reference".
- **Mutable objects** (e.g., lists) change globally; **immutable objects** (e.g., integers) don’t.
  ```python
  def myFun(x):
      x[0] = 20

  lst = [10, 11, 12, 13]
  myFun(lst)
  print(lst)  # Modified

  def myFun2(x):
      x = 20

  a = 10
  myFun2(a)
  print(a)  # Unchanged
  ```
  #### Output:
  ```
  [20, 11, 12, 13]
  10
  ```

### 1.9 Recursive Functions
- A function calling itself, with a base case to avoid infinite recursion.
  ```python
  def factorial(n):
      if n == 0:
          return 1
      else:
          return n * factorial(n - 1)

  print(factorial(4))
  ```
  #### Output:
  ```
  24
  ```

## 2. Python Pass Statement
- A placeholder that does nothing, ensuring valid syntax for empty blocks.
- Used in functions, loops, conditionals, and classes.

### 2.1 Using in Functions
```python
def fun():
    pass

fun()  # No action
```
#### Explanation: Function is valid but empty.

### 2.2 Using in Conditional Statements
```python
x = 10
if x > 5:
    pass  # Placeholder
else:
    print("x is 5 or less")
```
#### Explanation: No action for `x > 5`.

### 2.3 Using in Loops
```python
for i in range(5):
    if i == 3:
        pass  # Skip action
    else:
        print(i)
```
#### Output:
```
0
1
2
4
```

### 2.4 Using in Classes
```python
class EmptyClass:
    pass  # Empty class

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def greet(self):
        pass  # Placeholder method

p = Person("Emily", 30)
```
#### Explanation: Structures are valid for future implementation.

## 3. Global and Local Variables

### 3.1 Local Variables
- Defined inside functions, exist only during execution.
  ```python
  def greet():
      msg = "Hello from inside the function!"
      print(msg)

  greet()
  ```
  #### Output:
  ```
  Hello from inside the function!
  ```

  - Accessing outside causes error:
  ```python
  def greet():
      msg = "Hello!"
      print("Inside function:", msg)

  greet()
  print("Outside function:", msg)  # NameError
  ```
  #### Output:
  ```
  Traceback (most recent call last):
    ...
  NameError: name 'msg' is not defined
  ```

### 3.2 Global Variables
- Defined outside functions, accessible everywhere.
  ```python
  msg = "Python is awesome!"
  def display():
      print("Inside function:", msg)

  display()
  print("Outside function:", msg)
  ```
  #### Output:
  ```
  Inside function: Python is awesome!
  Outside function: Python is awesome!
  ```

### 3.3 Local vs Global with Same Name
- Local shadows global inside the function.
  ```python
  def fun():
      s = "Me too."
      print(s)

  s = "I love Geeksforgeeks"
  fun()
  print(s)
  ```
  #### Output:
  ```
  Me too.
  I love Geeksforgeeks
  ```

### 3.4 Modifying Global Variables
- Requires `global` keyword to modify.
  - Without `global` (error):
  ```python
  def fun():
      s += ' GFG'  # UnboundLocalError

  s = "I love GeeksforGeeks"
  fun()
  ```
  #### Output:
  ```
  UnboundLocalError: local variable 's' referenced before assignment
  ```

  - With `global`:
  ```python
  s = "Python is great!"
  def fun():
      global s
      s += " GFG"
      print(s)
      s = "Look for GeeksforGeeks Python Section"
      print(s)

  fun()
  print(s)
  ```
  #### Output:
  ```
  Python is great! GFG
  Look for GeeksforGeeks Python Section
  Look for GeeksforGeeks Python Section
  ```

### 3.5 Global vs Local Example
```python
a = 1
def f():
    print("f():", a)

def g():
    a = 2
    print("g():", a)

def h():
    global a
    a = 3
    print("h():", a)

print("global:", a)
f()
print("global:", a)
g()
print("global:", a)
h()
print("global:", a)
```
#### Output:
```
global: 1
f(): 1
global: 1
g(): 2
global: 1
h(): 3
global: 3
```
#### Explanation:
- `f()` uses global `a`.
- `g()` creates local `a`, leaving global unchanged.
- `h()` modifies global `a`.

### 3.6 Comparison
| **Aspect**            | **Global Variable**         | **Local Variable**         |
|-----------------------|-----------------------------|----------------------------|
| **Definition**        | Outside functions          | Inside functions           |
| **Lifetime**          | Program start to end       | Function call to return    |
| **Data Sharing**      | Shared across functions    | Not shared                 |
| **Scope**             | Anywhere in program        | Within function            |
| **Parameters**        | No parameter needed        | May use parameters         |
| **Storage**           | Global namespace           | Function stack frame       |
| **Value**             | Affects entire program     | Local changes only         |
