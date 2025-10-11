# 🎯 Local Variables

# Example 1: In this code, we are creating and accessing a local variable inside a function.
def fun1():
    msg = "Hi from inside fun1!"
    print(msg)

fun1()

# Example 2: In this example, we are creating a local variable inside a function and then trying to access it outside the function, which causes an error.
def fun():
    msg = "Hello!"
    print("Inside function:", msg)

fun()

# trying to access the local variable outside the function
try :
    print("Outside function:", msg)
except NameError:
    print("Variable msg is not defined outside the function.")

# 🎯 Global Variables

globalMsg = "this is a global variable"

def fun3():
    print("Inside fun3:", globalMsg)

fun3()
print("outside fun3:", globalMsg)

# 🎯 Use of Local and Global variables
print("🎯 Use of Local and Global variables")

# If a variable is defined both globally and locally with the same name, the local variable shadows the global variable inside the function. Changes to the local variable do not affect the global variable unless you explicitly declare the variable as global.

def fun4():
    s = "this is a local variable"
    print("Inside fun4:", s)

s = "this is a global variable"
fun4()
print("Outside fun4:", s)

def fun5():
    global globalMsg
    globalMsg = "this is a global variable"
    print("Inside fun:", globalMsg)

fun()
print("Outside fun:", globalMsg)

# 🎯 Modifying Global Variables Inside a Function
print("🎯 Modifying Global Variables Inside a Function")

def fun6():
    try:    
         s += ' GFG'   # Error: Python thinks s is local 
    except:
        s = "I love GeeksforGeeks"
    print(s)

s = "I love GeeksforGeeks"
fun6()

# With global (works correctly)
print("🎯 With global (works correctly)")

s = "Python is great!"

def fun7():
    global s
    s += " GFG"   # Modify global variable
    print(s)
    s = "Look for GeeksforGeeks Python Section"  # Reassign global
    print(s)

fun7()
print(s)

# 🎯 Global vs Local with Same Name
print("🎯 Global vs Local with Same Name")

a = 1 

def fun8():
    print(a)
def fun9():
    a = 2 # local shadow global
    print(a)

def fun10():
    global a
    a = 3 # global
    print(a)

print("fun8 - Global:",a)
fun8()
print("fun9 - Global",a)
fun9()
print("fun10 - Global",a)
fun10()
print("Global",a)