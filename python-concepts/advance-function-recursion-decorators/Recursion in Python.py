# 👉 Recursion is a programming technique where a function calls itself either directly or indirectly to solve a problem by breaking it into smaller, simpler subproblems.

# 👉 Examples of Recursion 

# Example 1: Factorial Calculation

def factorial(num):
    if num == 0: # Base Case
        return 1
    else: 
        return num * factorial(num - 1)

print(factorial(5)) # Output: 120

# Example 2: Fibonacci Sequence
def fibonacci(num):
    if num == 0:
        return 0
    elif num == 1:
        return 1
    else:
        return fibonacci(num - 1) + fibonacci(num - 2)
print(fibonacci(10)) # Output: 55

# 👉 Types of Recursion in Python
# tail recursion and non-tail recursion. The main difference between them is related to what happens after recursive call.

# Tail Recursion: The recursive call is the last thing the function does, so nothing happens after it returns. Some languages can optimize this to work like a loop, saving memory.

def tail_recursion(num, acc = 1):
    if num == 0:
        return acc
    else:
        return tail_recursion(num - 1, acc * num)
print(tail_recursion(5)) # Output: 120

# Non-Tail Recursion: The function does more work after the recursive call returns, so it can’t be optimized into a loop.

def non_tail_recursion(num):
    if num == 0:
        return 1
    else:
        return num * non_tail_recursion(num - 1)
print(non_tail_recursion(5)) # Output: 120

# # Explanation:
# def tail_fact(n, acc=1): - Defines a tail-recursive factorial function with an accumulator acc to store intermediate results.
# if n == 0: return acc - Base case: when n reaches 0, return the accumulated result.
# return tail_fact(n-1, acc * n) - Tail-recursive call: multiplies acc by n before the call, so no extra work is left after recursion.
# def nontail_fact(n): - Defines a non-tail-recursive factorial function.
# if n == 1: return 1 - Base case: factorial of 1 is 1.
# return n * nontail_fact(n-1) - Non-tail call: multiplication happens after the recursive call returns, so more work remains after recursion.

# 👉 How to Convert Non-Tail Recursion to Tail Recursion ?
# The key idea is to use an accumulator to store the result of the recursive call.

def convert_to_tail_recursion(num, acc = 1):
    if num == 0:
        return acc
    else:
        return convert_to_tail_recursion(num - 1, acc * num)
print(convert_to_tail_recursion(5)) # Output: 120

# 👉 Recursion vs Iteration
# It is often more intuitive and easier to implement when the problem is naturally recursive, like tree traversals. It can lead to solutions that are easier to understand compared to iterative ones.

# Iteration involves loops (for, while) to repeat the execution of a block of code. It is generally more memory-efficient as it does not involve multiple stack frames like recursion.

# 👉 When to Avoid Recursion

# When the problem can be solved easily with loops.
# When recursion depth is large enough to risk a stack overflow.
# When performance is critical and function call overhead matters.
# When performance is critical and function call overhead matters.

# 👉 Advantages

# Simplicity: Recursive code is generally simpler and cleaner, especially for problems inherently recursive in nature (e.g., tree traversals, dynamic programming problems).
# Reduced Code Length: Recursion can reduce the length of the code since the repetitive tasks are handled through repeated function calls.

# 👉 Disadvantages

# Memory Overhead: Each recursive call adds a new layer to the stack, which can result in significant memory use, especially for deep recursion.
# Performance Issues: Recursive functions may lead to slower responses due to overheads like function calls and returns.
# Risk of Stack Overflow: Excessive recursion can lead to a stack overflow error if the recursion depth exceeds the stack limit.