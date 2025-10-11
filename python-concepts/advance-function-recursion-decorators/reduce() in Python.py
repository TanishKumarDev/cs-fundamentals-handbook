# reduce() Function Kya Hai?

# Ye iterable ke saare elements ko combine karke ek hi single value return karta hai.
# Matlab, repeatedly 2-2 elements par function apply karega.
# Iske liye functools module se import karna padta hai:

# from functools import reduce

# Examples
# Example 1 – Normal Function (Sum of List)

from functools import reduce

def add(nums1, nums2):
    return nums1 + nums2

original_values = [1, 2, 3, 4, 5]
result = reduce(add, original_values) # Process: (((1+2)+3)+4)+5 = 15
print(result) 

# Lambda Function

original_values = [1, 2, 3, 4, 5]
sum_result = reduce(lambda x, y:x+y, original_values) # Process: (((1+2)+3)+4)+5 = 15
print(sum_result) 

# Example 3 – Product of List

a = [1, 2, 3, 4]
product_result = reduce(lambda x, y: x * y, a)
print(product_result)

# Example 4 – With Initial Value
a = [1, 2, 3, 4]
product_result = reduce(lambda x, y: x * y, a, 10) 
print(product_result)

# String Concatenation

words = ["geeks", "for", "geeks"]
res = reduce(lambda x, y: x + y, words)
print(res)