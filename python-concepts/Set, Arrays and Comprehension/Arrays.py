arr1 = [1, "Hi", 3.5, True, 4+5j]
print(arr1)

# Accessing Elements of an Array
print("Accessing Elements of an Array",arr1[0])

# Adding Elements to an Array
arr1.append(6)
print("Adding Elements to an Array",arr1)

# NumPy Arrays
import numpy as np
print(np.__version__)
arr2 = np.array([1, 2, 3, 4, 5])

print("NumPy Arrays",arr2)
print("Multiplying NumPy Arrays",arr2 * 2)
print("Adding NumPy Arrays",arr2 + 2)
print("Subtracting NumPy Arrays",arr2 - 2)
print("Dividing NumPy Arrays",arr2 / 2)
print("Modulus NumPy Arrays",arr2 % 2)
print("Power NumPy Arrays",arr2 ** 2)
print("Floor Division NumPy Arrays",arr2 // 2)
print("Square Root NumPy Arrays",np.sqrt(arr2))
print("Exponential NumPy Arrays",np.exp(arr2))
print("Logarithmic NumPy Arrays",np.log(arr2))

# Arrays