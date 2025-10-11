# Creating a file is the first step before writing data to it. In Python, we can create a file using the following three modes:

# Write ("w") Mode: This mode creates a new file if it doesn't exist. If the file already exists, it truncates the file (i.e., deletes the existing content) and starts fresh.
# Append ("a") Mode: This mode creates a new file if it doesn't exist. If the file exists, it appends new content at the end without modifying the existing data.
# Exclusive Creation ("x") Mode: This mode creates a new file only if it doesn't already exist. If the file already exists, it raises a FileExistsError.

import os


with open('example.txt', 'w') as file:  # Open a file in write mode
    file.write('Hello, World!\n')      # Write to the file
    file.write('This is a new line.\n') # Write another line
    print("File created and data written in write mode.")


with open('example.txt', 'r') as reading_file:
        print(reading_file.read())

# check if file exists
print(os.path.exists('example.txt'))    # True
print(os.path.exists('examplell.txt'))  # False