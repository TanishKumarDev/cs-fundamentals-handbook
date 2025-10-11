# Python Basics: Data Types, Operators, and Conditional Statements

## 1. Python Data Types
![alt text](https://media.geeksforgeeks.org/wp-content/uploads/20241210131752166623/Python-Data-Types.webp)
### 1.1 Overview
- Data types classify data items and define allowable operations.
- Everything in Python is an object; variables are instances of these classes.

### 1.2 Standard Built-in Data Types
- **Numeric**: `int`, `float`, `complex`
- **Sequence Type**: `str`, `list`, `tuple`
- **Mapping Type**: `dict`
- **Boolean**: `bool`
- **Set Type**: `set`, `frozenset`
- **Binary Types**: `bytes`, `bytearray`, `memoryview`

#### Example:
```python
x = 50      # int
x = 60.5    # float
x = "Hello World"  # str
x = ["geeks", "for", "geeks"]  # list
x = ("geeks", "for", "geeks")  # tuple
```

### 1.3 Numeric Data Types
- **Integers (`int`)**: Whole numbers (no limit).
- **Float**: Real numbers with decimal points.
- **Complex**: `(real part) + (imaginary part)j`.

#### Example:
```python
a = 5
b = 5.0
c = 2 + 4j
print(type(a), type(b), type(c))
```

#### Output:
```
<class 'int'> <class 'float'> <class 'complex'>
```

### 1.4 Sequence Data Types
- Ordered collections of items.

#### String (`str`)
- Arrays of Unicode characters; created with single, double, or triple quotes.
- Access via index.

#### Example:
```python
s = 'Welcome to the Geeks World'
print(s)
print(type(s))
print(s[1], s[2], s[-1])
```

#### Output:
```
Welcome to the Geeks World
<class 'str'>
e l d
```

#### List
- Ordered, mutable collections; created with `[]`.

#### Example:
```python
a = [1, 2, 3]
b = ["Geeks", "For", "Geeks", 4, 5]
print(a)
print(b)
```

#### Output:
```
[1, 2, 3]
['Geeks', 'For', 'Geeks', 4, 5]
```

#### Access List Items:
```python
a = ["Geeks", "For", "Geeks"]
print(a[0], a[2])
print(a[-1], a[-3])
```

#### Output:
```
Geeks Geeks
Geeks Geeks
```

#### Tuple
- Ordered, immutable collections; created with `()` or commas.

#### Example:
```python
tup1 = ()
tup2 = ('Geeks', 'For')
print("Tuple with the use of String:", tup2)
```

#### Output:
```
Tuple with the use of String: ('Geeks', 'For')
```

#### Access Tuple Items:
```python
tup1 = tuple([1, 2, 3, 4, 5])
print(tup1[0], tup1[-1], tup1[-3])
```

#### Output:
```
1 5 3
```

### 1.5 Boolean Data Type
- Values: `True`, `False` (class `bool`).
- Case-sensitive.

#### Example:
```python
print(type(True))
print(type(False))
# print(type(true))  # Raises NameError
```

#### Output:
```
<class 'bool'>
<class 'bool'>

Traceback (most recent call last):
  File "...", line ..., in <module>
    print(type(true))
NameError: name 'true' is not defined
```

### 1.6 Set Data Type
- Unordered, mutable, no duplicates; created with `set()` or `{}`.

#### Example:
```python
s1 = set()
s1 = set("GeeksForGeeks")
s2 = set(["Geeks", "For", "Geeks"])
print("Set with the use of String:", s1)
print("Set with the use of List:", s2)
```

#### Output:
```
Set with the use of String: {'s', 'o', 'F', 'G', 'e', 'k', 'r'}
Set with the use of List: {'Geeks', 'For'}
```

#### Access Set Items:
```python
set1 = set(["Geeks", "For", "Geeks"])
print(set1)
for i in set1:
    print(i, end=" ")
print("Geeks" in set1)
```

#### Output:
```
{'For', 'Geeks'}
For Geeks True
```

### 1.7 Dictionary Data Type
- Key-value pairs; keys are immutable, values can be duplicated.

#### Example:
```python
d = {}
d = {1: 'Geeks', 2: 'For', 3: 'Geeks'}
d1 = dict({1: 'Geeks', 2: 'For', 3: 'Geeks'})
print(d)
print(d1)
```

#### Output:
```
{1: 'Geeks', 2: 'For', 3: 'Geeks'}
{1: 'Geeks', 2: 'For', 3: 'Geeks'}
```

#### Access Key-value:
```python
d = {1: 'Geeks', 'name': 'For', 3: 'Geeks'}
print(d['name'])
print(d.get(3))
```

#### Output:
```
For
Geeks
```

## 2. Python Operators

### 2.1 Overview
- Symbols used to perform operations on values and variables.

### 2.2 Types of Operators
- **Arithmetic**: `+`, `-`, `*`, `/`, `//`, `%`, `**`
- **Comparison**: `>`, `<`, `==`, `!=`, `>=`, `<=`
- **Logical**: `and`, `or`, `not`
- **Bitwise**: `&`, `|`, `~`, `^`, `>>`, `<<`
- **Assignment**: `=`, `+=`, `-=`, `*=`, `<<=`
- **Identity**: `is`, `is not`
- **Membership**: `in`, `not in`
- **Ternary**: Conditional expression

#### Arithmetic Operators Example:
```python
a = 15
b = 4
print("Addition:", a + b)
print("Subtraction:", a - b)
print("Multiplication:", a * b)
print("Division:", a / b)
print("Floor Division:", a // b)
print("Modulus:", a % b)
print("Exponentiation:", a ** b)
```

#### Output:
```
Addition: 19
Subtraction: 11
Multiplication: 60
Division: 3.75
Floor Division: 3
Modulus: 3
Exponentiation: 50625
```

#### Comparison Operators Example:
```python
a = 13
b = 33
print(a > b, a < b, a == b, a != b, a >= b, a <= b)
```

#### Output:
```
False True False True False True
```

#### Logical Operators Example:
```python
a = True
b = False
print(a and b, a or b, not a)
```

#### Output:
```
False True False
```

#### Bitwise Operators Example:
```python
a = 10
b = 4
print(a & b, a | b, ~a, a ^ b, a >> 2, a << 2)
```

#### Output:
```
0 14 -11 14 2 40
```

#### Assignment Operators Example:
```python
a = 10
b = a
print(b)
b += a
print(b)
b -= a
print(b)
b *= a
print(b)
b <<= a
print(b)
```

#### Output:
```
10 20 10 100 102400
```

#### Identity Operators Example:
```python
a = 10
b = 20
c = a
print(a is not b, a is c)
```

#### Output:
```
True True
```

#### Membership Operators Example:
```python
x = 24
y = 20
lst = [10, 20, 30, 40, 50]
if x not in lst:
    print("x is NOT present in given list")
if y in lst:
    print("y is present in given list")
```

#### Output:
```
x is NOT present in given list
y is present in given list
```

#### Ternary Operator Example:
```python
a, b = 10, 20
min = a if a < b else b
print(min)
```

#### Output:
```
10
```

#### Precedence and Associativity Example:
```python
print(10 + 20 * 30)
print(100 / 10 * 10)
print(5 - 2 + 3)
print(5 - (2 + 3))
print(2 ** 3 ** 2)
```

#### Output:
```
610
100.0
6
0
512
```

## 3. Conditional Statements in Python

### 3.1 Overview
- Control program flow based on conditions.

### 3.2 Types
- **If Statement**
- **If-Else Statement**
- **If-Elif-Else Statement**
- **Nested If-Else**
- **Ternary Statement**
- **Match-Case Statement**

#### If Statement Example:
```python
age = 20
if age >= 18:
    print("Eligible to vote.")
```

#### Output:
```
Eligible to vote.
```

#### If-Else Statement Example:
```python
age = 10
if age <= 12:
    print("Travel for free.")
else:
    print("Pay for ticket.")
```

#### Output:
```
Travel for free.
```

#### If-Elif-Else Statement Example:
```python
age = 25
if age <= 12:
    print("Child.")
elif age <= 19:
    print("Teenager.")
elif age <= 35:
    print("Young adult.")
else:
    print("Adult.")
```

#### Output:
```
Young adult.
```

#### Nested If-Else Example:
```python
age = 70
is_member = True
if age >= 60:
    if is_member:
        print("30% senior discount!")
    else:
        print("20% senior discount.")
else:
    print("Not eligible for a senior discount.")
```

#### Output:
```
30% senior discount!
```

#### Ternary Statement Example:
```python
age = 20
s = "Adult" if age >= 18 else "Minor"
print(s)
```

#### Output:
```
Adult
```

#### Match-Case Statement Example:
```python
number = 2
match number:
    case 1:
        print("One")
    case 2 | 3:
        print("Two or Three")
    case _:
        print("Other number")
```

#### Output:
```
Two or Three
```

## 4. Practical Solved Problems

### 4.1 If Statement
- **Problem 1: Vote Eligibility**
```python
age = int(input("Enter your age: "))
if age >= 18:
    print("You are eligible to vote.")
```
- **Output:**
```
Enter your age: 22
You are eligible to vote.
```

- **Problem 2: Positive Number**
```python
num = int(input("Enter a number: "))
if num > 0:
    print("The number is positive.")
```
- **Output:**
```
Enter a number: 4
The number is positive.
```

### 4.2 If-Else Statement
- **Problem 1: Exam Result**
```python
marks = int(input("Enter your marks: "))
if marks >= 40:
    print("You passed the exam.")
else:
    print("You failed the exam.")
```
- **Output:**
```
Enter your marks: 98
You passed the exam.
```

- **Problem 2: Purchase Check**
```python
balance = float(input("Enter your balance: "))
price = float(input("Enter the item price: "))
if balance >= price:
    print("Purchase successful.")
else:
    print("Insufficient funds.")
```
- **Output:**
```
Enter your balance: 100.50
Enter the item price: 56.55
Purchase successful.
```

### 4.3 If-Elif-Else Statement
- **Problem 1: Transport Suggestion**
```python
distance = float(input("Enter the distance to your destination (in km): "))
if distance <= 2:
    print("You can walk.")
elif distance <= 10:
    print("Use a bicycle or scooter.")
elif distance <= 50:
    print("Take a car or public transport.")
else:
    print("Consider a train or flight.")
```
- **Output:**
```
Enter the distance to your destination (in km): 240
Consider a train or flight.
```

- **Problem 2: Battery Status**
```python
battery = int(input("Enter battery percentage: "))
if battery > 80:
    print("Battery Full")
elif battery > 40:
    print("Battery Half")
else:
    print("Battery Low")
```
- **Output:**
```
Enter battery percentage: 55
Battery Half
```

### 4.4 Nested If-Else Statement
- **Problem 1: Login Authentication**
```python
username = input("Enter username: ")
password = input("Enter password: ")
if username == "admin":
    if password == "1234":
        print("Access granted")
    else:
        print("Incorrect password")
else:
    print("Username not found")
```
- **Output:**
```
Enter username: admin
Enter password: 12345
Incorrect password
```

- **Problem 2: Exam and Scholarship**
```python
marks = int(input("Enter your marks: "))
if marks >= 50:
    if marks >= 80:
        print("Passed with scholarship")
    else:
        print("Passed without scholarship")
else:
    print("Failed")
```
- **Output:**
```
Enter your marks: 89
Passed with scholarship
```

### 4.5 Ternary Statement
- **Problem 1: Even/Odd**
```python
num = int(input("Enter a number: "))
print("Even" if num % 2 == 0 else "Odd")
```
- **Output:**
```
Enter a number: 77
Odd
```

- **Problem 2: Compare Numbers**
```python
a = int(input("Enter value of a: "))
b = int(input("Enter value of b: "))
print("a is greater" if a > b else "b is greater")
```
- **Output:**
```
Enter value of a: 33
Enter value of b: 12
a is greater
```

- **Problem 3: Temperature Check**
```python
temp = int(input("Enter the temperature: "))
print("Hot" if temp > 25 else "Cool")
```
- **Output:**
```
Enter the temperature: 33
Hot
```

### 4.6 Match-Case Statement
- **Problem 1: Assign Grade**
```python
grade = input("Enter your grade (A/B/C): ").upper()
match grade:
    case "A":
        print("Excellent")
    case "B":
        print("Good")
    case "C":
        print("Average")
    case _:
        print("Fail")
```
- **Output:**
```
Enter your grade (A/B/C): A
Excellent
```

- **Problem 2: Activity Suggestion**
```python
weather = input("Enter the weather (sunny/rainy/cloudy/snowy): ").lower()
match weather:
    case "sunny":
        print("Great day for a picnic!")
    case "rainy":
        print("Stay indoors and read a book.")
    case "cloudy":
        print("Perfect time for a walk.")
    case "snowy":
        print("Build a snowman or go skiing!")
    case _:
        print("Unknown weather condition.")
```
- **Output:**
```
Enter the weather (sunny/rainy/cloudy/snowy): sunny
Great day for a picnic!
```

- **Problem 3: Notification Settings**
```python
mode = input("Enter phone mode (silent/vibrate/loud/do not disturb): ").lower()
match mode:
    case "silent":
        print("Notifications are muted.")
    case "vibrate":
        print("Phone will vibrate for notifications.")
    case "loud":
        print("All notifications will play sound.")
    case "do not disturb":
        print("No calls or notifications will come through.")
    case _:
        print("Invalid mode selected.")
```
- **Output:**
```
Enter phone mode (silent/vibrate/loud/do not disturb): loud
All notifications will play sound.
```
