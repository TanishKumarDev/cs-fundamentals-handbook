# 👉 OrderedDict in Python
# The OrderedDict class (from the collections module) is a subclass of dict that remembers the order in which keys were inserted.

# 👉 Key Points
# Before Python 3.7, normal dict did not guarantee order → OrderedDict was necessary.

# From Python 3.7+, normal dict preserves insertion order by default.

# OrderedDict is still useful because it has extra features:

    # Reorder keys with move_to_end().

    # Pop items from start or end with popitem(last=True/False).

    # Equality checks are order-sensitive (OrderedDict([('a',1),('b',2)]) != OrderedDict([('b',2),('a',1)])).

# ✅ Example: Preserves Insertion Order
from collections import OrderedDict

od = OrderedDict()
od["apple"] = 1
od["banana"] = 2
od["cherry"] = 3

print(list(od.items()))  # Output: [('apple', 1), ('banana', 2), ('cherry', 3)]

# ✅ Extra Features

# Reordering keys
od.move_to_end("banana")
print(list(od.items()))  # Output: [('apple', 1), ('cherry', 3), ('banana', 2)]

od.move_to_end("cherry", last=False)
print(list(od.items()))  # Output: [('cherry', 3), ('apple', 1), ('banana', 2)]

# Pop from either end
od.popitem(last=True)
print(list(od.items()))  # Output: [('apple', 1), ('banana', 2)]

od.popitem(last=False)
print(list(od.items()))  # Output: [('banana', 2)]

# Equality check considers order
od1 = OrderedDict([("a", 1), ("b", 2)])
od2 = OrderedDict([("b", 2), ("a", 1)])
print(od1 == od2)  # Output: False

# Reversing order
d1 = OrderedDict([('a', 1), ('b', 2), ('c', 3)])
d2 = OrderedDict(reversed(list(d1.items())))
print(d2)  # OrderedDict([('c', 3), ('b', 2), ('a', 1)])

# ✅ When to use OrderedDict today?

# If you’re working with Python < 3.7.

# If you need special methods like move_to_end(), popitem(last=False), or order-sensitive comparisons.

# If your program depends heavily on controlling key order.

# ⚡ In short:

# Normal dict is enough for most cases in modern Python.

# Use OrderedDict only when you need its special order-manipulating featur