# if
age = 10

if age >= 18:
    print("You are an adult")

# short hand
if age > 18 : print("You are an adult")

# if...else
marks = 100
if marks>= 75:
    print("You are an Pass")
else:
    print("You are not an Fail")

# short hand
if marks > 75 : print("You are an Pass")
else : print("You are not an Fail")

# elif - else if
age = 18

if age <= 12:
    print("You are a child")
elif age <= 18:
    print("You are a teenager")
else:
    print("You are an adult")

# Nested if..else statement
age = 18

if age <= 12:
    print("You are a child")
else:
    if age <= 18:
        print("You are a teenager")
    else:
        print("You are an adult")

# Ternary Operator
age = 18

result = "You are an adult" if age >= 18 else "You are not an adult"
print(result)

# Short Hand
print("You are an adult") if age >= 18 else print("You are not an adult")


# match-case

number = 2

match number:
    case 1:
        print("One")
    case 2:
        print("Two")
    case 3:
        print("Three")
    case _:
        print("Invalid")