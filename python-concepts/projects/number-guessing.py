def guessNumber(startRange, endRange):
    if startRange > endRange:
        return "Invalid range"
    
    # middle of the range
    mid = (startRange + endRange) // 2

    # asking user about the actual number
    print(f"Is your number {mid}? (Y/N): ", end="")
    response = input().strip().upper()

    # guess correctly
    if response == 'Y':
        print(f"Yay! I guessed your number {mid} correctly!")
        return True
    # guess incorrectly
    elif response == 'N':
        print(f"Is your number greater than {mid}? (Y/N): ", end="")
        response = input().strip().upper()
        
        if response == 'Y':
            return guessNumber(mid + 1, endRange)
        elif response == 'N':
            return guessNumber(startRange, mid - 1)
        else:
            print("Invalid input. Please respond with 'Y' or 'N'.")
            return guessNumber(startRange, endRange)
    else:
        print("Invalid input. Please respond with 'Y' or 'N'.")
        return guessNumber(startRange, endRange)
    

# Driver code
if __name__ == "__main__":
    print("Welcome to the Number Guessing Game!")
    
    # Input range from user
    startRange = int(input("Enter the start of the range: "))
    endRange = int(input("Enter the end of the range: "))

    print(f"Think of a number between {startRange} and {endRange}.")
    print("Tell me when you are ready, then I will start guessing!")
    
    ready = input("Can I guess now? (Y/N): ").strip().upper()
    if ready == 'Y':
        result = guessNumber(startRange, endRange)
        if not result:
            print("Couldn't guess it, are you sure you answered correctly?")
    else:
        print("Okay, run the game again when you're ready!")
