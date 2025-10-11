# Python Basics: Loops

## 1. Overview
- Loops in Python repeat actions efficiently, with main types being `for` loops (iterating over sequences) and `while` loops (condition-based repetition).

## 2. For Loop
- Iterates over a sequence (list, tuple, string, range).
- Syntax:
  ```python
  for iterator_var in sequence:
      statement(s)
  ```

### 2.1 Basic Example
```python
n = 4
for i in range(0, n):
    print(i)
```
#### Output:
```
0
1
2
3
```
#### Explanation: Prints numbers 0 to 3 using `range(0, n)`.

### 2.2 Iterating Over Sequences
```python
li = ["geeks", "for", "geeks"]
for i in li:
    print(i)

tup = ("geeks", "for", "geeks")
for i in tup:
    print(i)

s = "Geeks"
for i in s:
    print(i)

d = dict({'x': 123, 'y': 354})
for i in d:
    print("%s %d" % (i, d[i]))

set1 = {1, 2, 3, 4, 5, 6}
for i in set1:
    print(i, end=" ")
```
#### Output:
```
geeks
for
geeks
geeks
for
geeks
G
e
e
k
s
x 123
y 354
1 2 3 4 5 6
```

### 2.3 Iterating by Index
```python
li = ["geeks", "for", "geeks"]
for index in range(len(li)):
    print(li[index])
```
#### Output:
```
geeks
for
geeks
```
#### Explanation: Uses indices to access list elements.

### 2.4 Using `else` with For Loop
```python
li = ["geeks", "for", "geeks"]
for index in range(len(li)):
    print(li[index])
else:
    print("Inside Else Block")
```
#### Output:
```
geeks
for
geeks
Inside Else Block
```
#### Explanation: `else` executes after the loop completes.

## 3. While Loop
- Executes a block repeatedly while a condition is true.
- Syntax:
  ```python
  while expression:
      statement(s)
  ```

### 3.1 Basic Example
```python
cnt = 0
while (cnt < 3):
    cnt = cnt + 1
    print("Hello Geek")
```
#### Output:
```
Hello Geek
Hello Geek
Hello Geek
```

### 3.2 Using `else` with While Loop
```python
cnt = 0
while (cnt < 3):
    cnt = cnt + 1
    print("Hello Geek")
else:
    print("In Else Block")
```
#### Output:
```
Hello Geek
Hello Geek
Hello Geek
In Else Block
```
#### Explanation: `else` executes when the condition becomes false.

### 3.3 Infinite While Loop
```python
while (True):
    print("Hello Geek")
```
#### Note: Runs indefinitely; use `break` to exit (not recommended without termination logic).

## 4. Nested Loops
- One loop inside another.
- Syntax (for nested `for`):
  ```python
  for iterator_var in sequence:
      for iterator_var in sequence:
          statement(s)
  ```
- Syntax (for nested `while`):
  ```python
  while expression:
      while expression:
          statement(s)
  ```

### 4.1 Example
```python
from __future__ import print_function
for i in range(1, 5):
    for j in range(i):
        print(i, end=' ')
    print()
```
#### Output:
```
1 
2 2 
3 3 3 
4 4 4 4
```
#### Explanation: Prints `i` multiple times per row, increasing with each outer loop iteration.

## 5. Loop Control Statements
- Modify loop execution flow.

### 5.1 Continue Statement
- Skips the current iteration and moves to the next.
```python
for letter in 'geeksforgeeks':
    if letter == 'e' or letter == 's':
        continue
    print('Current Letter:', letter)
```
#### Output:
```
Current Letter: g
Current Letter: k
Current Letter: f
Current Letter: o
Current Letter: r
Current Letter: g
Current Letter: k
```
#### Explanation: Skips 'e' and 's'.

### 5.2 Break Statement
- Exits the loop prematurely.
```python
for letter in 'geeksforgeeks':
    if letter == 'e' or letter == 's':
        break
print('Current Letter:', letter)
```
#### Output:
```
Current Letter: e
```
#### Explanation: Stops at the first 'e' or 's'.

### 5.3 Pass Statement
- Placeholder for empty loops.
```python
for letter in 'geeksforgeeks':
    pass
print('Last Letter:', letter)
```
#### Output:
```
Last Letter: s
```
#### Explanation: No action; prints the last letter.

## 6. How For Loop Works Internally
- Uses iterators (`iter()` and `next()`).
### Example 1:
```python
fruits = ["apple", "orange", "kiwi"]
for fruit in fruits:
    print(fruit)
```
### Example 2 (Manual Iteration):
```python
fruits = ["apple", "orange", "kiwi"]
iter_obj = iter(fruits)
while True:
    try:
        fruit = next(iter_obj)
        print(fruit)
    except StopIteration:
        break
```
#### Output (both examples):
```
apple
orange
kiwi
```
#### Explanation: `for` internally calls `iter()` and `next()`.

## 7. Practice Problems

### 7.1 For Loops
- **Problem 1: Print Shopping List**
```python
items = input("Enter shopping items separated by commas: ").split(',')
for item in items:
    print("Buy:", item.strip())
```
#### Output:
```
Enter shopping items separated by commas: milk, bread, eggs, avocado, oats
Buy: milk
Buy: bread
Buy: eggs
Buy: avocado
Buy: oats
```

- **Problem 2: Print Squares**
```python
n = int(input("Enter a number: "))
for i in range(1, n + 1):
    print("Square of", i, "is", i**2)
```
#### Output:
```
Enter a number: 4
Square of 1 is 1
Square of 2 is 4
Square of 3 is 9
Square of 4 is 16
```

### 7.2 While Loops
- **Problem 1: Countdown Timer**
```python
seconds = int(input("Enter countdown time in seconds: "))
while seconds > 0:
    print("Time left:", seconds)
    seconds -= 1
```
#### Output:
```
Enter countdown time in seconds: 5
Time left: 5
Time left: 4
Time left: 3
Time left: 2
Time left: 1
```

- **Problem 2: Sum Until Zero**
```python
total = 0
num = int(input("Enter number (0 to stop): "))
while num != 0:
    total += num
    num = int(input("Enter number (0 to stop): "))
print("Total sum:", total)
```
#### Output:
```
Enter number (0 to stop): 22
Enter number (0 to stop): 44
Enter number (0 to stop): 0
Total sum: 66
```

### 7.3 Nested For Loops
- **Problem 1: Multiplication Table**
```python
n = 3
for i in range(1, n + 1):
    for j in range(1, 11):
        print(i * j, end=' ')
    print()
```
#### Output:
```
1 2 3 4 5 6 7 8 9 10
2 4 6 8 10 12 14 16 18 20
3 6 9 12 15 18 21 24 27 30
```

- **Problem 2: Identity Matrix**
```python
n = 4
for i in range(n):
    for j in range(n):
        if i == j:
            print("1", end=" ")
        else:
            print("0", end=" ")
    print()
```
#### Output:
```
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
```

### 7.4 Control Flow Statements
- **Break**
  - **Problem 1: Stop at Target**
  ```python
  items = ["apple", "banana", "cherry", "stop", "mango"]
  for item in items:
      if item == "stop":
          break
      print("Item:", item)
  ```
  #### Output:
  ```
  Item: apple
  Item: banana
  Item: cherry
  ```

  - **Problem 2: Find First Even**
  ```python
  while True:
      num = int(input("Enter a number: "))
      if num % 2 == 0:
          print("First even number found:", num)
          break
  ```
  #### Output:
  ```
  Enter a number: 3
  Enter a number: 5
  Enter a number: 6
  First even number found: 6
  ```

- **Continue**
  - **Problem 1: Skip Out-of-Stock**
  ```python
  items = ["milk", "bread", "out of stock", "eggs"]
  for item in items:
      if item == "out of stock":
          continue
      print("Buy:", item)
  ```
  #### Output:
  ```
  Buy: milk
  Buy: bread
  Buy: eggs
  ```

  - **Problem 2: Skip Even Numbers**
  ```python
  n = 10
  for i in range(1, n + 1):
      if i % 2 == 0:
          continue
      print("Odd number:", i)
  ```
  #### Output:
  ```
  Odd number: 1
  Odd number: 3
  Odd number: 5
  Odd number: 7
  Odd number: 9
  ```

- **Pass**
  - **Problem 1: Future Implementation**
  ```python
  tasks = ["email", "meeting", "call"]
  for task in tasks:
      if task == "call":
          pass  # Logic to be added later
      print("Do:", task)
  ```
  #### Output:
  ```
  Do: email
  Do: meeting
  Do: call
  ```

  - **Problem 2: Empty Loop**
  ```python
  for i in range(5):
      pass  # Placeholder for future logic
  ```
  #### Explanation: No action; reserved for future use.

