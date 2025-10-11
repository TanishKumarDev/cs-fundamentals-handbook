# if Statement
# Problem 1: Check if user is eligible to vote
age = int(input("Enter your age: "))
if age >= 18:
    print("You are eligible to vote.")

# Problem 2: Check if a number is positive

num = int(input("Enter a number: "))

if num > 0:
    print("The number is positive.")


# if-else Statement
# Problem 1: Check if a student is pass/fail in exam.

marks = int(input("Enter marks: "))

if marks >= 40:
    print("You passed the exam.")
else:
    print("You failed the exam.")

# Problem 2: Check if a user has balance to buy an item

balance = float(input("Enter your balance: "))
price = float(input("Enter the price of the item: "))

if(balance > price):
    print("You have enough balance to buy the item.")
else:
    print("You don't have enough balance to buy the item.")

# if-elif-else Statement
# Problem 1: Suggest a mode of transport based on distance

distance = float(input("Enter the distance(in KMs): "))

if distance < 5:
    print("Walk")
elif distance < 10:
    print("Bicycle")
else:
    print("Car")

# Problem 2: Battery status

battery_level = int(input("Enter battery percentage: "))

if battery_level > 80:
    print("Battery is fully charged.")

elif battery_level > 40:
    print("Battery is half charged.")

else:
    print("Battery is low.")

# Nested if-else Statement

# Problem 1: Login with username and password
username = input("Enter username: ")
password = input("Enter password: ")

if username == "admin":
    if password == "1234":
        print("Login successful!")
    else:
        print("Invalid username or password.")
else:
    print("Invalid username or password.")

# Problem 2: Check exam pass and scholarship eligibility

marks = int(input("Enter marks: "))

if marks >= 40:
    print("You passed the exam.")
    if marks >= 75:
        print("You are eligible for scholarship.")
    else:
        print("You are not eligible for scholarship.")
else:
    print("You failed the exam.")

# Ternary Statement

# Problem 1: Check if number is even
num = int(input("Enter a number: "))
print("The number is even") if num % 2 == 0 else print("The number is odd")

# Problem 2: Compare two numbers

num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))

print("num1 is greater" if num1 > num2 else "num2 is greater")

# Problem 3: Temperature checker

temp = float(input("Enter the temperature: "))
print("Hot" if temp > 25 else "Cold")

# Match- case Statement
# Problem 1: Assign grade

grade = input("Enter your grade (A/B/C): ").upper()

match grade:
    case "A":
        print("Excellent")
    case "B":
        print("Good")
    case "C":
        print("Average")
    case _:
        print("Fail")

# Problem 2: Activity Suggestion based on weather condition
weather = input("Enter the weather (sunny/rainy/cloudy/snowy): ").lower()

match weather:
    case "sunny":
        print("Great day for a picnic!")
    case "rainy":
        print("Stay indoors and read a book.")
    case "cloudy":
        print("Perfect time for a walk.")
    case "snowy":
        print("Build a snowman or go skiing!")
    case _:
        print("Unknown weather condition.")
        
# Problem 3: Mobile notification settings based on user profile mode
mode = input("Enter phone mode (silent/vibrate/loud/do not disturb): ").lower()

match mode:
    case "silent":
        print("Notifications are muted.")
    case "vibrate":
        print("Phone will vibrate for notifications.")
    case "loud":
        print("All notifications will play sound.")
    case "do not disturb":
        print("No calls or notifications will come through.")
    case _:
        print("Invalid mode selected.")