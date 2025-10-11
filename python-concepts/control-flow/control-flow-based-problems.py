# Python Loops Practice Problems

# 1. For Loops
# Problem 1: Print Shopping List
shopping_items = input("Enter items separated by commas: ").split(',')
for item in shopping_items:
    print("Buy: ",item.strip())

# Problem 2: Print Squares of Numbers
num = int(input("Enter a number: "))
for i in range(1, num + 1):
    print("Square of", i, "is", i * i)

# 2. While Loops
# Problem 1: Countdown Timer
seconds = int(input("Enter seconds for countdown: "))
while seconds > 0:
    print("Time left:", seconds, "seconds")
    seconds -= 1
print("Time's up!")

# Problem 2: Sum Until Zero
total = 0
num = int(input("Enter number (0 to stop): "))
while num != 0:
    total += num
    num = int(input("Enter number (0 to stop): "))
print("Total sum:", total)

# 3. Nested For Loops
# Problem 1: Multiplication Table
n = 3
for i in range(1, n + 1):
    for j in range(1, 11):
        print(i * j, end=' ')
    print()

# Problem 2: Identity Matrix Pattern
n = 4
for i in range(n):
    for j in range(n):
        print("1" if i == j else "0", end=" ")
    print()

# 4. Control Flow Statements in Loops

# 4.1 break
# Problem 1: Stop Printing at Target Item

items = ["apple", "banana", "cherry", "date"]
target = "cherry"
for item in items:
    if item == target:
        break
    print("Item:", item)

# Problem 2: Find First Even Number
while True:
    num = int(input("Enter a number: "))
    if num % 2 == 0:
        print("First even number found:", num)
        break

# 4.2 continue

# Problem 1: Skip Out-of-Stock Items
items = ["milk", "bread", "out of stock", "eggs"]
for item in items:
    if item == "out of stock":
        continue
    print("Buy:", item)

# Problem 2: Skip Even Numbers
n = 10
for i in range(1, n + 1):
    if i % 2 == 0:
        continue
    print("Odd number:", i)

# 4.3 pass
# Problem 1: Placeholder for Future Code
tasks = ["email", "meeting", "call"]
for task in tasks:
    if task == "call":
        pass  # Logic to be added later
    print("Do:", task)

# Problem 2: Empty Loop
for i in range(5):
    pass  # Loop does nothing