# Sequence Containers in C++

## 1. Overview

In the C++ Standard Template Library (STL), **containers** are objects that store collections of data.
**Sequence containers** maintain the **order** of elements — they store data **in a linear sequence**, similar to arrays or lists.

The major **sequence containers** are:

1. **`vector`** – dynamic array
2. **`deque`** – double-ended queue
3. **`list`** – doubly linked list
4. **`forward_list`** – singly linked list (introduced in C++11)
5. **`array`** – fixed-size array (introduced in C++11)

We’ll start with **`vector`**, as it’s the most widely used and powerful among them.

---

# Vector in C++ STL

## 2. What is a Vector?

A **`vector`** is a **dynamic array** that can **resize itself** automatically when elements are inserted or deleted.

In simple terms:

* Think of it as an **array with superpowers**.
* You don’t need to manually manage memory or size.
* When it runs out of space, it **allocates new memory**, copies existing elements, and continues.

It’s part of the **Standard Template Library (STL)** and defined in the `<vector>` header.

```cpp
#include <vector>
using namespace std;
```

---

## 3. Why Use a Vector?

Traditional arrays have limitations:

* Fixed size (decided at compile-time)
* Manual memory management
* No built-in operations like insertion or deletion

Vectors solve these problems by providing:

* **Automatic resizing**
* **Type safety**
* **Random access**
* **STL function support**

If you need a resizable array with **fast random access** and **frequent insertions at the end**, `vector` is your best choice.

---

## 4. How Does Vector Work Internally?

* A vector maintains an **internal array**.
* It has:

  * **Size** → number of elements currently stored.
  * **Capacity** → total space allocated before resizing is needed.
* When inserting beyond capacity:

  * A **new larger array** is created.
  * Old elements are **copied**.
  * The old memory is **freed**.

So, insertion at the end (`push_back`) is **amortized O(1)** — meaning fast on average — but resizing occasionally takes **O(n)**.

---

## 5. Syntax and Declaration

```cpp
vector<T> v;
```

Here:

* `T` is the data type.
* `v` is the vector’s name.

Examples:

```cpp
vector<int> v1;              // Empty vector of integers
vector<int> v2(3, 5);        // Vector with 3 elements, each initialized to 5
vector<int> v3 = {1, 2, 3};  // Initialization using list
```

---

## 6. Insertion Operations

### (a) `push_back(value)`

Adds an element to the **end** of the vector.

**Time Complexity:** Amortized O(1)

```cpp
vector<int> v = {1, 2, 3};
v.push_back(4); // v = {1, 2, 3, 4}
```

### (b) `insert(iterator, value)`

Inserts an element **at a specific position**.

**Time Complexity:** O(n) – shifts elements

```cpp
v.insert(v.begin() + 1, 10); // insert 10 at index 1
// v = {1, 10, 2, 3, 4}
```

---

## 7. Accessing Elements

### (a) Using `operator[]`

```cpp
cout << v[2]; // Access 3rd element (index starts at 0)
```

### (b) Using `at(index)`

Safe access with bounds checking.

```cpp
cout << v.at(2);
```

If `index` is out of range, it throws an **`out_of_range`** exception.

---

## 8. Updating Elements

You can modify an element using its index:

```cpp
v[1] = 50;
```

This updates the second element to 50.

---

## 9. Finding Size and Capacity

```cpp
cout << v.size();      // Current number of elements
cout << v.capacity();  // Total allocated space (may be larger)
```

---

## 10. Traversing a Vector

There are multiple ways to iterate:

### (a) Index-based loop

```cpp
for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
```

### (b) Range-based for loop

```cpp
for (int x : v)
    cout << x << " ";
```

### (c) Using Iterators

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
```

---

## 11. Deletion Operations

### (a) `pop_back()`

Removes the **last element**.
**O(1)** time.

```cpp
v.pop_back();
```

### (b) `erase(iterator)`

Removes an element from a specific position.
**O(n)** time due to shifting.

```cpp
v.erase(v.begin() + 2); // Remove element at index 2
```

### (c) `clear()`

Removes all elements.

```cpp
v.clear();
```

---

## 12. Checking If Vector Is Empty

```cpp
if (v.empty()) {
    cout << "Vector is empty";
}
```

---

## 13. Multidimensional Vectors

Vectors can store vectors — allowing **2D** or even **3D structures**.

### Example: 2D Vector

```cpp
vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

cout << matrix[1][2]; // prints 6
```

### Traversal

```cpp
for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

---

## 14. Common Member Functions

| Function         | Description                 | Time Complexity |
| ---------------- | --------------------------- | --------------- |
| `push_back(x)`   | Insert element at end       | O(1) amortized  |
| `pop_back()`     | Remove last element         | O(1)            |
| `insert(pos, x)` | Insert at specific position | O(n)            |
| `erase(pos)`     | Remove specific element     | O(n)            |
| `clear()`        | Remove all elements         | O(n)            |
| `size()`         | Get current size            | O(1)            |
| `empty()`        | Check if empty              | O(1)            |
| `at(i)`          | Access with bounds check    | O(1)            |
| `front()`        | First element               | O(1)            |
| `back()`         | Last element                | O(1)            |
| `swap(v2)`       | Swap contents               | O(1)            |

---

## 15. Example Program – Complete Overview

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    // Insert
    v.push_back(40);
    v.insert(v.begin() + 2, 25);

    // Update
    v[0] = 5;

    // Access
    cout << "Element at index 2: " << v.at(2) << endl;

    // Traverse
    cout << "Vector elements: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Delete
    v.pop_back();
    v.erase(v.begin() + 1);

    // Check empty
    if (v.empty())
        cout << "Vector is empty\n";
    else
        cout << "Vector not empty, size = " << v.size() << endl;

    return 0;
}
```

---

## 16. When to Use `vector`

Use `vector` when:

* You need **random access**.
* You often **add/remove elements at the end**.
* You don’t know the number of elements in advance.
* You want **cache-friendly** and **fast iteration**.

Avoid `vector` when:

* You frequently insert/delete elements **in the middle**.
  (In that case, `list` or `deque` may be better.)

---

## 17. Key Takeaways

* `vector` = resizable array.
* Fast random access → O(1)
* Efficient end insertions → O(1) amortized
* Costly middle insertions/deletions → O(n)
* Supports STL algorithms (`sort`, `find`, etc.)
* Essential foundation for mastering **STL sequence containers**
