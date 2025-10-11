# Python set is an unordered collection of multiple items having different datatypes. In Python, sets are mutable, unindexed and do not contain duplicates. The order of elements in a set is not preserved and can change.

set1 = {1,2,3,4}
print(set1)

# Using the set() function
set2 = set([1,2,3,4,5])
print("Using the set() function ",set2)

# # Creating a Set with the use of a tuple
tup = (1,2,3,4,5)
print("Creating a Set with the use of a tuple",set(tup))

# # Creating a Set with the use of a dictionary
dict = {"a":1,"b":2,"c":3}
print("Creating a Set with the use of a dictionary",set(dict))

# Unordered, Unindexed and Mutability
set2 = {"apple","banana","cherry"}
print("Unordered, Unindexed and Mutability",set2)

# Unindexed: Accessing elements by index is not possible
# This will raise a TypeError
try:
    print(set2[0])
except TypeError as e:
    print("Error:", e)

# Adding Elements to a Set in Python
set2.add("orange")
print("Adding Elements to a Set in Python",set2)

# Accessing a Set in Python
print("Accessing a Set in Python",set2)

for i in set2:
    print(i, end=" ")

# Checking if an Element is Present in a Set in Python
print("Checking if an Element is Present in a Set in Python", "orange" in set2)

# Removing Elements from a Set in Python
set2.remove("banana")
print("Removing Elements from a Set in Python",set2)

# Removing an Element from a set that is not present will raise a KeyError
try:
    set2.remove("banana")
except KeyError as e:
    print("Error:", e)

# Removing an Element from a Set using the discard() method
set2.discard("banana")
print("Removing an Element from a Set using the discard() method",set2)

# Removing an Element from a Set using the pop() method
set2.pop()
print("Removing an Element from a Set using the pop() method",set2)

# Clearing a Set in Python
set2.clear()
print("Clearing a Set in Python",set2)

# Frozen Sets in Python - A frozenset in Python is a built-in data type that is similar to a set but with one key difference that is immutability. This means that once a frozenset is created, we cannot modify its elements that is we cannot add, remove or change any items in it. Like regular sets, a frozenset cannot contain duplicate elements
frozen_set = frozenset([1,2,3,4,5])
print("Frozen Sets in Python",frozen_set)

# Creating a Frozen Set from a String
set4 = frozenset("Geeksforgeeks")
frozen_set = frozenset(set4)
print("Creating a Frozen Set from a String",set4)

# Typecasting Objects into Sets
li = [1,2,3,4,5]
print("Typecasting Objects into Sets",set(li))

# Typecasting String into set
s = "Geeksforgeeks"
print("Typecasting String into set",set(s))

# Typecasting dictionary into set
d = {1: "One", 2: "Two", 3: "Three"}
print("Typecasting dictionary into set",set(d))