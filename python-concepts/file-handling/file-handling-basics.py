# 👉 Basic Example: Opening a File
file = open('example.txt', 'w')  # Open a file in write mode
file.write('Hello, World!')      # Write to the file
file.close()                     # Close the file

# 👉 Check file properties
print("File Name:", file.name)
print("File Mode:", file.mode)
print("Is File Closed?", file.closed)
print("File Encoding:", file.encoding)

# 👉 Reading a File
file = open('example.txt', 'r')  # Open the file in read mode
content = file.read()            # Read the content of the file
print("File Content:", content)
file.close()                     # Close the file 

# 👉 Using with Statement
with open('example.txt', 'a') as file:  # Open the file in append mode
    file.write('\nAppending a new line.')  # Append a new line to the file
    file.write('\nAgain Appending a new line.')  # Append a new line to the file

# Handling Exceptions When Closing a File
try:
    file = open('example.txt', 'r')
    content = file.read()
    print("File Content with Exception Handling:", content)
finally:
    file.close()

# 👉 Explanation
# try: Starts the block to handle code that might raise an error.
# open(): Opens the file in read mode.
# read(): Reads the content of the file.
# finally: Ensures the code inside it runs no matter what.
# close(): Safely closes the file to free resources.