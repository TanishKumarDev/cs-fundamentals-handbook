# The pass statement in Python is a placeholder that does nothing when executed. It is used to keep code blocks valid where a statement is required but no logic is needed yet, such as in empty functions, classes, loops or conditional blocks. Without pass, leaving these blocks empty would cause an error.

# Using in Functions
def fun():
    pass

fun() # Do nothing

# Using in Conditional Statements
num = 1;
if num > 5:
    pass # Do nothing now ; placeholder for future logic
else:
    print("Number is less than 5") 

# Using in loops
for i  in range(5):
    if i == 2:
        pass # do nothing when i is 2
    else:
        print(i)

# Using in Classes
class EmptyClass:
    pass  # No methods or attributes yet

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def greet(self):
        pass  # Placeholder for greet method

# Creating an instance of the class
p = Person("Emily", 30)