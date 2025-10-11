# 👉 Python map() function is used to apply a function to each item in an iterable (list, tuple, etc.).
# Syntax: map(function, iterable)
# Important: map() ek map object (iterator) return karta hai, isko list/tuple me convert karna padta hai.

# Example:

# Basic Example
s = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
result = map(int, s) 
print(list(result))

# 1. Without map()
squared_nums = []
for nums in [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]:
    squared_nums.append(nums * 2)
print(squared_nums)

# 2. With map()
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
squared_nums = list(map(lambda nums: nums * 2, nums))
print(squared_nums)

# Converting map object to list
nums = [1,2,3]

def double(val):
    return val * 2;

result = list(map(double, nums))
print(result)

# map() with lambda
a = [1, 2, 3, 4]
res = list(map(lambda x: x * 2, a))
print(res)

# map() with Multiple Iterables
a = [1, 2, 3]
b = [4, 5, 6]

res = list(map(lambda x, y: x + y, a, b))
print(res)

# Strings to Uppercase
fruits = ['apple', 'banana', 'cherry']
res = list(map(str.upper, fruits))
print(res)

# Extract First Character
words = ['apple', 'banana', 'cherry']
res = list(map(lambda s: s[0], words))
print(res)

# Remove Whitespaces
s = ['  hello  ', '  world ', ' python  ']
res = list(map(str.strip, s))
print(res)

# Celsius → Fahrenheit Conversion
celsius = [0, 20, 37, 100]
fahrenheit = list(map(lambda c: (c * 9/5) + 32, celsius))
print(fahrenheit)
