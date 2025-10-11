# 🎯 Arithmetic Operators
# Variables
a = 15
b = 4

# Addition
print("Addition:", a + b)  

# Subtraction
print("Subtraction:", a - b) 

# Multiplication
print("Multiplication:", a * b)  

# Division
print("Division:", a / b) 
 
# Floor Division
print("Floor Division:", a // b)  

# Modulus
print("Modulus:", a % b) 

# Exponentiation
print("Exponentiation:", a ** b)

# 🎯 Comparison Operators
a = 13
b = 33

print(a > b)
print(a < b)
print(a == b)
print(a != b)
print(a >= b)
print(a <= b)

# 🎯 Logical Operators
# 🎯 Logical Operators

a = True
b = False
print(a and b)
print(a or b)
print(not a)

# 🎯 Bitwise Operators

a = 10
b = 4

print(a & b)
print(a | b)
print(~a)
print(a ^ b)
print(a >> 2)
print(a << 2)

# 🎯 Assignment Operators

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

# 🎯 Identity Operators

a = 10
b = 20
c = a

print(a is not b)
print(a is c)


# 🎯 Membership  Operators -  in and not in are the membership operators that are used to test whether a value or variable is in a sequence.

x = 24
y = 20
list = [10, 20, 30, 40, 50]

if (x not in list):
    print("x is NOT present in given list")
else:
    print("x is present in given list")

if (y in list):
    print("y is present in given list")
else:
    print("y is NOT present in given list")