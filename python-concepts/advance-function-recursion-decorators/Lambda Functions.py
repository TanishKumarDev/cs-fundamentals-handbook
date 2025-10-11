# 👉 Lambda Function Kya Hai?

# Normal function 
def add(a, b):
    return a + b
print(add(10, 20))

# Lambda function
add = lambda a, b: a + b
print(add(10, 20))

# 👉 Lambda with Condition Checking
check = lambda nums: "Positive" if nums > 0 else "Negative"

print(check(-10))
print(check(0))
print(check(10))

# 👉 Lambda with Multiple Conditions
check = lambda nums1, nums2: "Grenums1ter" if nums1 > nums2 else "Smnums1ller" if nums1 < nums2 else "Equal"

print(check(10, 20))
print(check(20, 10))
print(check(10, 10))

# 👉 Lambda with List Comprehension
li = [lambda arg=x: arg * 10 for x in range(1, 5)]
for f in li:
    print(f())

# 👉 Lambda with If-Else
check = lambda nums: "Even" if nums % 2 == 0 else "Odd"
print(check(10))
print(check(11))

# 👉 Lambda with Multiple Operations
calc = lambda nums1, nums2: (nums1 + nums2, nums1 - nums2, nums1 * nums2, nums1 / nums2)
print(calc(10, 20))

# 👉 Lambda with filter()
# Filter ek list se sirf specific elements rakhta hai.
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
even_nums = list(filter(lambda nums: nums % 2 == 0, nums))
print(even_nums)

# 👉 Lambda with map()
# Map ek list ko modify karta hai.
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
modified_nums = list(map(lambda nums: nums * 2, nums))
print(modified_nums)

# 👉 Lambda with map()
# Reduce ek list ko reduce karta hai.
from functools import reduce
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
sum_nums = reduce(lambda nums1, nums2: nums1 + nums2, nums)
print(sum_nums)

# 👉 Lambda with reduce()
# Reduce ek list ko reduce karta hai.
from functools import reduce
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
sum_nums = reduce(lambda nums1, nums2: nums1 + nums2, nums)
print(sum_nums)

# ✅ Summary (easy yaad rakhne ka rule):

# lambda = shortcut function

# filter() → elements filter karo

# map() → har element ko transform karo

# reduce() → sabko mila ke ek result banao