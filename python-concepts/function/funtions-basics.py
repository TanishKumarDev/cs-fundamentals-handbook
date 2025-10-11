# 1. Function Declaration and Calling
def greet():
    print("Welcome to GFG")

greet()  # Function call

# 2. Function Arguments

# 2.1 Positional Arguments
# Arguments are assigned based on order.
def positional_name_age(name, age):
    print("Hi, I am", name, "and my age is", age)

positional_name_age("Alice", 20)  # Correct

# 2.2 Default Arguments
# If a value isn’t provided, a default is used.
def default_name_age(name="Bob", age=25):
    print("Hi, I am", name, "and my age is", age)
default_name_age()  # Uses default values
default_name_age("Charlie")  # Overrides name, uses default age
default_name_age(age=30)  # Overrides age, uses default name

# 2.3 Keyword Arguments
# Specify arguments by name; order doesn’t matter.
def keyword_name_age(fname, lname):
    print("Hi, I am", fname, lname)

keyword_name_age(lname="Smith", fname="David")  # Order doesn’t matter

# 2.4 Arbitrary Arguments (*args, **kwargs)
# Pass variable numbers of arguments.
def arbitrary_args(*args, **kwargs):
    print("Non-keyword arguments:", args)
    for arg in args:
        print(arg)
    print("\nKeyword arguments:", kwargs)
    for key, value in kwargs.items():
        print(f"{key}: {value}")
arbitrary_args('Hey', 'Welcome', first='Geeks', mid='for', last='Geeks')

# 3. Function Within Functions (Nested Functions)
def outer_function():
    print("This is the outer function.")
    
    def inner_function():
        print("This is the inner function.")
    
    inner_function()  # Call inner function

outer_function()

# 4. Anonymous Functions (Lambda)
cube = lambda x: x ** 3
print("Cube of 3 is:", cube(3))

# 5. Return Statement
# Returns a value from a function.
def square(num):
    return num * num
print("Square of 4 is:", square(4))

# 6. Pass by Reference vs Pass by Value
# In Python, functions pass arguments by object reference, not by value.
# This means that if the argument is an immutable object (like an int or a str), it will remain unchanged.
# If the argument is a mutable object (like a list or a dict), any changes made to it inside the function will be reflected outside the function.

# Mutable objects (lists, dicts) → modifications inside the function affect original.
def modify_list(lst):
    lst[0] = 20

lst = [10, 11, 12]
modify_list(lst)
print(lst)  # [20, 11, 12]

# Immutable objects (int, str, tuple) → original value remains unchanged.
def modify_int(x):
    x = 20

a = 10
modify_int(a)
print(a)  # 10

# 7. Recursive Functions
def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)

print("Factorial of 5 is:", factorial(5))