# 👉 args and **kwargs are used to allow functions to accept an arbitrary number of arguments. These features provide great flexibility when designing functions that need to handle a varying number of inputs.
# Example: This example shows how *args collects multiple positional arguments into a tuple and how **kwargs collects keyword arguments into a dictionary.

# 👉 1. Non-Keyword Arguments (*args) : It is used to pass a variable number of positional arguments to a function. 
# Matlab: Function ko jitne bhi values dena ho, woh tuple me collect ho jati hain.
# The special syntax *args allows us to pass any number of positional (non-keyword) arguments to a function. These arguments are collected into a tuple, which means we can loop through them or use them with built-in functions.
# This is useful when you don’t know in advance how many values will be passed.

def add_all(*args):
    print(args)  # tuple ban jayega
    print(type(args))
    return sum(args)
print(add_all(1, 2, 3, 4, 5))
print(add_all(10, 20, 30, 40, 50))

# 👉 2. Keyword Arguments (**kwargs) : It is used to pass a variable number of keyword arguments to a function.
# Matlab: Function ko key=value ke form me input dete ho.
# Ye sab ek dictionary me collect hote hain.
# The special syntax **kwargs allows us to pass any number of keyword arguments (arguments in the form key=value). These arguments are collected into a dictionary, where:
    # Keys = argument names
    # Values = argument values
# This is useful when you want your function to accept flexible, named inputs.

def show_details(**kwargs):
    print(kwargs) # dictionary me print ho jati hai
    for key, value in kwargs.items():
        print(key, value)
print(show_details(a=1, b=2, c=3, d=4, e=5))

# 👉 *args + **kwargs together
def student_details(*args, **kwargs):
    print(" Subjects ",args) # tuple ban jayega
    print(" Details ",kwargs) # dictionary ban jayega
print(student_details("Math", "Science", "English", name="John", age=20))