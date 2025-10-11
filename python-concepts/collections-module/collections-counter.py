# 👉 The collections module is a built-in Python library that provides specialized container datatypes (like dictionaries, lists, sets, and tuples, but with extra features or optimizations).

# 👉 It’s part of the Python Standard Library, so you don’t need to install anything — just import collections.

# 👉 Why use collections?

# Sometimes the built-in types (list, dict, set, tuple) are not enough or not efficient for certain tasks. The collections module provides enhanced versions of these data structures.

# 👉 Common classes in collections
# namedtuple() Tuple subclass with named fields (like lightweight objects).
from collections import namedtuple
Point = namedtuple('Point', ['x', 'y'])
p = Point(1, 2)
print(p.x, p.y)  # Output: 1 2

# deque (double-ended queue)
# list-like container optimized for fast appends and pops from both ends.

from collections import deque
d = deque([1, 2, 3])
d.appendleft(0)  # Add to the left
d.append(4)      # Add to the right
print(d)  # Output: deque([0, 1, 2, 3, 4])

# Counter 
# A dictionary subclass for counting hashable objects.
from collections import Counter
c = Counter("banana")
print(c)  # Counter({'a': 3, 'n': 2, 'b': 1})
print(c.most_common(1))  # [('a', 3)]

# OrderedDict (in Python 3.7+, regular dicts also preserve order)
# Dictionary that remembers insertion order.
from collections import OrderedDict

od = OrderedDict()
od["a"] = 1
od["b"] = 2
print(od)  # OrderedDict([('a', 1), ('b', 2)])

# defaultdict
# Like a normal dict, but provides a default value for missing keys.
from collections import defaultdict

dd = defaultdict(int)   # default value is 0
dd["a"] += 1
print(dd)  # defaultdict(<class 'int'>, {'a': 1})

# 👉 Why use collections.Counter?
# A subclass of dict that counts the frequency of elements in an iterable (list, string, tuple, etc.) or from a mapping (dictionary).

# 👉 Why use it instead of a normal dictionary?
# Saves time — no need to write manual counting loops.
# Provides handy built-in methods (most_common(), elements(), etc.).
# Clean, efficient, and flexible for different input types.

# Creating Counters
from collections import Counter

# From a list
ctr1 = Counter([1, 2, 2, 3, 3, 3])
# From a dictionary
ctr2 = Counter({1: 2, 2: 3, 3: 1})
# From a string
ctr3 = Counter("hello")

print(ctr1)  
print(ctr2)  
print(ctr3) 

# Accessing Counts
ctr = Counter("hello")
print(ctr['h'])  # Output: 1
print(ctr['e'])  # Output: 1
print(ctr['l'])  # Output: 2
print(ctr['o'])  # Output: 1

# Updating Counters
ctr.update("world")
print(ctr)  # Output: Counter({'l': 3, 'o': 2, 'w': 1, 'r': 1, 'd': 1})

# Useful Methods
# elements() → expands Counter back into elements
print(list(ctr.elements()))  # Output: ['h', 'e', 'l', 'l', 'l', 'o', 'o', 'w', 'r', 'd']

# most_common(n) → returns the n most common elements
print(ctr.most_common(2))  # Output: [('l', 3), ('o', 2)]

# subtract() → subtracts counts from another Counter
ctr.subtract(Counter("world"))
print(ctr)  # Output: Counter({'h': 1, 'e': 1, 'l': 1, 'o': 0, 'w': -1, 'r': -1, 'd': -1})

# Arithmetic Operations
ctr1 = Counter([1, 2, 2, 3])
ctr2 = Counter([2, 3, 3, 4])

print("Addition ", ctr1 + ctr2) # Addition
print("Subtraction ", ctr1 - ctr2) # Subtraction
print("Intersection ", ctr1 & ctr2) # Intersection
print("Union ", ctr1 | ctr2) # Union

# ⚡ In short:
# Counter = fast, dictionary-like frequency counter
# Perfect for tasks like:
    # Word frequency in text
    # Voting systems
    # Inventory management