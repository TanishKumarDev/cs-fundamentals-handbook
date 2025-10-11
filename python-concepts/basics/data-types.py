# Numeric - int, float, complex
x = 10
y = 3.14
z = 2 + 3j

# Sequence Type - string, list, tuple
s = "Hello"
lst = [1, 2, 3, 'a', 'b', 'c']
tup = (4, 5, 6)

# Mapping Type - dict
dic = {"name": "Tanish", "age": 21}

# Boolean - bool
flag = true

# Set Type - set, frozenset

# set → unordered, mutable, unique elements
st = {1, 2, 3}
# frozenset → unordered, immutable, unique elements
fs = frozenset({4, 5, 6})

# Binary Types - bytes, bytearray, memoryview
# bytes → immutable sequence of bytes
b = b"Hello"
# bytearray → mutable sequence of bytes
ba = bytearray([65, 66, 67])
# memoryview → memory view of a bytes-like object
mv = memoryview(b"Hello")

# ⚡ Summary Table

# Category	Types
# Numeric	int, float, complex
# Sequence	str, list, tuple
# Mapping	dict
# Boolean	bool
# Set	set, frozenset
# Binary	bytes, bytearray, memoryview

# 🎯 Python Built-in Data Types with Mutability

# | **Category** | **Type**     | **Mutable?**  | **Example**                  |
# | ------------ | ------------ | ------------- | ---------------------------- |
# | **Numeric**  | `int`        | ❌ Immutable  | `x = 5`                     |
# |              | `float`      | ❌ Immutable  | `y = 3.14`                  |
# |              | `complex`    | ❌ Immutable  | `z = 2 + 3j`                |
# | **Sequence** | `str`        | ❌ Immutable  | `s = "hello"`               |
# |              | `list`       | ✅ Mutable    | `lst = [1, 2, 3]`           |
# |              | `tuple`      | ❌ Immutable  | `t = (1, 2, 3)`             |
# | **Mapping**  | `dict`       | ✅ Mutable    | `d = {"a": 1, "b": 2}`      |
# | **Boolean**  | `bool`       | ❌ Immutable  | `flag = True`               |
# | **Set**      | `set`        | ✅ Mutable    | `s = {1, 2, 3}`             |
# |              | `frozenset`  | ❌ Immutable  | `fs = frozenset([1, 2, 3])` |
# | **Binary**   | `bytes`      | ❌ Immutable  | `b = b"hello"`              |
# |              | `bytearray`  | ✅ Mutable    | `ba = bytearray([65, 66])`  |
# |              | `memoryview` | ✅ Mutable\*  | `mv = memoryview(b"hello")` |

# 📝 Notes:

# Immutable types: Once created, they cannot be changed. Reassignment creates a new object.

# Mutable types: Can be modified in-place (append, update, remove, etc.).

# memoryview is special → it provides a view of another object’s memory (can be used to modify underlying data if that object is mutable).