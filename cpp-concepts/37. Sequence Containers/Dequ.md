# **Deque**

## 1. Introduction

### What is a Deque?

A **Deque (Double-Ended Queue)** is a **sequence container** in the C++ Standard Template Library (STL) that allows insertion and deletion of elements **from both ends** — front and back.

It combines the functionalities of both **queue** and **stack**, offering flexibility in managing elements.

### Why Deque?

While a **vector** only allows fast insertion/removal at the end, a **deque** supports efficient insertion/removal **at both ends**, making it ideal for problems like:

* **Sliding window maximum/minimum**
* **Task scheduling**
* **Palindrome checking**
* **Undo/redo systems**

### How it Works Internally

A **deque** is implemented as a **dynamic array of fixed-size arrays**.
Unlike `vector`, which is stored in contiguous memory, deque elements are stored in **blocks**, allowing:

* Faster growth from both ends.
* Avoidance of frequent reallocation.
* Constant-time access by index (like vector).

---

## 2. Syntax and Declaration

```cpp
#include <deque>
using namespace std;

deque<int> d;                // Empty deque
deque<int> d2 = {10, 20, 30}; // Initialized deque
```

### Template Format

```cpp
deque<datatype> name;
```

Example:

```cpp
deque<string> dq;
deque<double> dq2(5, 1.1); // deque with 5 elements initialized to 1.1
```

---

## 3. Basic Operations on Deque

Let’s go step-by-step through all the major operations:

---

### 3.1 Insertion Operations

#### `push_back()` — Insert at the End

Adds an element to the **back** of the deque.

```cpp
deque<int> d;
d.push_back(10);
d.push_back(20);
d.push_back(30);
```

**Output:**
`10 20 30`

**Time Complexity:** O(1) amortized

---

#### `push_front()` — Insert at the Beginning

Adds an element to the **front** efficiently.

```cpp
deque<int> d;
d.push_front(30);
d.push_front(20);
d.push_front(10);
```

**Output:**
`10 20 30`

**Time Complexity:** O(1) amortized

---

### 3.2 Deletion Operations

#### `pop_back()` — Remove Last Element

Removes an element from the **back**.

```cpp
deque<int> d = {10, 20, 30, 40};
d.pop_back();
```

**Output:**
`10 20 30`

**Time Complexity:** O(1) amortized

---

#### `pop_front()` — Remove First Element

Removes the element from the **front**.

```cpp
deque<int> d = {10, 20, 30, 40};
d.pop_front();
```

**Output:**
`20 30 40`

**Time Complexity:** O(1) amortized

---

### 3.3 Accessing Elements

#### `front()` — Access First Element

Returns (but doesn’t remove) the first element.

```cpp
deque<int> d = {100, 200, 300};
cout << d.front();  // Output: 100
```

#### `back()` — Access Last Element

Returns (but doesn’t remove) the last element.

```cpp
deque<int> d = {10, 20, 30, 40};
cout << d.back();  // Output: 40
```

#### Random Access using Index

Deque supports **O(1)** direct index access.

```cpp
deque<int> d = {10, 20, 30, 40};
cout << d[2]; // Output: 30
```

---

### 3.4 Size and Capacity

#### `size()` — Number of Elements

```cpp
deque<int> d = {5, 10, 15};
cout << d.size(); // Output: 3
```

#### `empty()` — Check if Empty

```cpp
deque<int> d;
if (d.empty()) cout << "Deque is empty";
```

---

### 3.5 Clearing the Deque

#### `clear()` — Remove All Elements

```cpp
deque<int> d = {1, 2, 3, 4, 5};
d.clear();
cout << d.size(); // Output: 0
```

---

## 4. Iterating Through a Deque

### Using Range-Based Loop

```cpp
deque<int> d = {1, 2, 3, 4};
for (int x : d) cout << x << " ";
```

### Using Iterators

```cpp
for (auto it = d.begin(); it != d.end(); ++it)
    cout << *it << " ";
```

### Reverse Iteration

```cpp
for (auto it = d.rbegin(); it != d.rend(); ++it)
    cout << *it << " ";
```

---

## 5. Other Useful Member Functions

| Function              | Description                      |
| --------------------- | -------------------------------- |
| `begin()` / `end()`   | Iterator to first/last element   |
| `rbegin()` / `rend()` | Reverse iterators                |
| `at(index)`           | Safe access with bounds check    |
| `assign(n, val)`      | Assign multiple elements         |
| `erase(it)`           | Remove element at iterator       |
| `insert(it, val)`     | Insert before iterator           |
| `swap(d2)`            | Swap contents with another deque |

---

## 6. Time Complexity Summary

| Operation             | Time Complexity |
| --------------------- | --------------- |
| Insert front/back     | O(1) amortized  |
| Delete front/back     | O(1) amortized  |
| Random access         | O(1)            |
| Insert/Erase (middle) | O(n)            |
| Traversal             | O(n)            |

---

## 7. Comparison — Queue vs Deque

| Feature    | Queue                     | Deque                                   |
| ---------- | ------------------------- | --------------------------------------- |
| Definition | FIFO (First In First Out) | Double-ended structure                  |
| Operations | Enqueue, Dequeue          | Insert/Delete both ends                 |
| Access     | Only front and rear       | Both ends accessible                    |
| Use Cases  | Scheduling, buffering     | Sliding window, palindrome, undo system |

---

## 8. Real-World Example

### Problem:

You are maintaining a window of last 3 elements to calculate rolling sums.

### Solution using Deque:

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> window;
    int n;
    while (cin >> n) {
        window.push_back(n);
        if (window.size() > 3)
            window.pop_front();
        int sum = 0;
        for (int x : window)
            sum += x;
        cout << "Rolling sum: " << sum << endl;
    }
}
```

**Concept:**
Deque efficiently maintains the **sliding window** of size `k` using `push_back()` and `pop_front()` operations in O(1) time.

---

## 9. When to Use Deque?

| Scenario                         | Recommended Container |
| -------------------------------- | --------------------- |
| Insert/remove only at end        | `vector`              |
| Insert/remove at both ends       | `deque`               |
| Frequent insert/delete in middle | `list`                |
| Need strict FIFO                 | `queue`               |
| Need LIFO (stack behavior)       | `stack`               |

---

## 10. Final Takeaway

* `deque` = **dynamic, double-ended, efficient** structure.
* Offers **O(1)** access and insertion/deletion at both ends.
* Perfect for **sliding window**, **caching**, and **bidirectional processing** problems.
* Part of **Sequence Containers** along with `vector`, `list`, and `array`.

