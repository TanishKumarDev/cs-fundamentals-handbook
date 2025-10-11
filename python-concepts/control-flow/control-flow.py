# For Loop in Python
n = 4
for i in range(n):
    print("Iteration:", i) 

# Example:
# Iterating Over List, Tuple, String and Dictionary Using for Loops in Python

li = [1, 2, 3, 4]
for i in li:
    print(i)

tup = (5, 6, 7, 8)
for i in tup:
    print(i)

s = "Hello"
for i in s:
    print(i)

d = {"a": 1, "b": 2, "c": 3}
for i in d:
    print(i, d[i]) # prints keys and values

# 👉 Iterating by the Index of Sequences
# We can also use the index of elements in the sequence to iterate. The key idea is to first calculate the length of the list and then iterate over the sequence within the range of this length.

list1 = [10, 20, 30, 40]
for i in range(len(list1)):
    print(list1[i])
# The range(len(list)) generates indices from 0 to the length of the list minus 1.



# 👉 Using else Statement with for Loop in Python
list2 = [1, 2, 3]
for i in range(len(list2)):
    print(list2[i])
else:
    print("Loop completed")

# 👉 While Loop in Python
count = 0 
while(count < 5):
    count += 1
    print("Count:", count)

# 👉 Using else statement with While Loop in Python
count = 0
while(count < 5):
    count += 1
    print("Count:", count)
else:
    print("Loop completed")

# 👉 Infinite While Loop in Python
count = 0
while True:
    count += 1
    print("Count:", count)
    if count >= 5:
        break
# 👉 Nested Loops in Python
for i in range(3):
    for j in range(2):
        print("i:", i, "j:", j)

# 👉 Loop Control Statements - break, continue, pass

# Continue Statement
for i in range(5):
    if i == 2: # Skip the rest of the loop when i is 2
        continue
    print("i:", i)

# Break Statement
for i in range(5):
    if i == 2: # Stop the loop when i is 2
        break
    print("i:", i)

# Pass Statement
for i in range(5):
    if i == 2: # Do nothing when i is 2
        pass
    print("i:", i)

# Difference between break, continue and pass
# - break: stops the loop entirely
# - continue: skips the current iteration
# - pass: does nothing and moves to the next iteration

# 👉 How for loop works internally in Python?

# Example 1:
# This Python code iterates through a list called fruits, containing "apple", "orange" and "kiwi." It prints each fruit name on a separate line, displaying them in the order they appear in the list.

fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
    print("Current fruit:", fruit)

# Example 2:
# This Python code manually iterates through a list of fruits using an iterator. It prints each fruit's name one by one and stops when there are no more items in the list.

fruits = ["apple", "banana", "cherry"]
fruit_iterator = iter(fruits)
while True:
    try:
        fruit = next(fruit_iterator)
        print("Current fruit:", fruit)
    except StopIteration:
        break