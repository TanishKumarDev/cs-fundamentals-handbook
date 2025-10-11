# Reading from a file in Python means accessing and retrieving the contents of a file, whether it be text, binary data or a specific data format like CSV or JSON.

# Example: Reading the Entire File
file = open('example.txt', 'r')  # Open the file in read mode
content = file.read()            # Read the entire content of the file
print("File Content:\n", content)  # Print the content
file.close()                     # Close the file to free up resources

# Best Practice: Using with statement
with open('example.txt', 'r') as file:  # Open the file in read mode
    content = file.read()                # Read the entire content of the file
    print("File Content using with statement:\n", content)  # Print the content

# Reading a File Line by Line
file = open('example.txt', 'r')  # Open the file in read mode
print("Reading file line by line:")
for line in file:                # Iterate through each line in the file
    print(line.strip())          # Print each line, .strip() to remove newline characters
file.close()                     # Close the file
