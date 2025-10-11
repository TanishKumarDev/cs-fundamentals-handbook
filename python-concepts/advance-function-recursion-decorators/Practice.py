# 👉 Special Functions In Python
# 1. zip()
zipped = list(zip(list1, list2))
print(zipped)

# 2. filter() -> elements <= 2
filtered = list(filter(lambda x: x <= 2, list1))
print(filtered)

# 3. map() -> multiply by 2
mapped = list(map(lambda x: x * 2, list1))
print(mapped)

# 👉 Factorial
# Itrative
class Solution:
    # Function to calculate factorial of a number.
    def factorial(self, n: int) -> int:
        result = 1
        for i in range(1, n + 1):
            result *= i
        return result
# Recursive
class Solution:
    def factorial(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1
        return n * self.factorial(n - 1)

# 👉 Print 1 to n without using loops
class Solution:
    def printTillN(self, n):
        # Base Case
        if n == 0:
            return
        # Recursive Call
        self.printTillN(n - 1)
        # Print current number
        print(n, end=" ")

# 👉 Nth Fibonacci Number
class Solution:
    def nthFibonacci(self, n: int) -> int:
        # code here
        if n == 0:
            return 0
        if n == 1:
            return 1
        return self.nthFibonacci(n-1) + self.nthFibonacci(n-2)
# Time Complexity: O(2^n) → very slow for n=30.
# Space Complexity: O(n) (recursion stack).


# 👉 Majority Element
class Solution:
    def majorityElement(self, arr):
        n = len(arr)
        
        # Step 1: Find candidate using Boyer-Moore
        candidate, count = None, 0
        for num in arr:
            if count == 0:
                candidate = num
                count = 1
            elif num == candidate:
                count += 1
            else:
                count -= 1
        
        # Step 2: Verify candidate
        if arr.count(candidate) > n // 2:
            return candidate
        return -1
