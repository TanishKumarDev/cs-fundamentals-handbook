# 👉 When working with files in Python, the file mode tells Python what kind of operations (read, write, etc.) you want to perform on the file. 

# 1. Read Mode ('r')
with open('example.txt', 'r') as file:
    content = file.read()
    print("Read Mode Content:\n", content)

# 2. Write Mode ('w')
with open('example.txt', 'w') as file:
    file.write('Hello, World!\n')
    print("Write Mode: File overwritten with new content.")

# 3. Append Mode ('a')
with open('example.txt', 'a') as file:
    file.write('Appending a new line.\n')
    print("Append Mode: New content added to the end of the file.")

# 4. Binary Mode ('b')
with open('example.txt', 'rb') as file:
    binary_content = file.read()
    print("Binary Mode Content:\n", binary_content)

# 5. Read and Write Mode ('r+')
with open('example.txt', 'r+') as file:
    content = file.read()
    print("Read and Write Mode Original Content:\n", content)
    file.write('Adding more content in r+ mode.\n')
    print("Read and Write Mode: New content added.")

# 6. Write and Read Mode ('w+')
with open('example.txt', 'w+') as file:
    file.write('This is new content in w+ mode.\n')
    file.seek(0)  # Move the cursor to the beginning of the file
    content = file.read()
    print("Write and Read Mode Content:\n", content)