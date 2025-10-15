# **List in C++ STL**

## **1. Introduction**

### **What is a `list`?**

`std::list` is a **sequence container** in C++ STL that implements a **doubly linked list**.
It allows **non-contiguous storage** of elements, and each node maintains **two pointers** — one to the next node and one to the previous node.

Because of this, you can:

* Traverse both forward and backward,
* Insert or delete elements efficiently **anywhere** in the list (beginning, middle, or end).

---

### **Why Use a List?**

* When frequent **insertions or deletions** are required at **both ends or in the middle**.
* When you don’t need **random access** like arrays or vectors.
* When **memory relocation** (like vector resizing) is not acceptable.

---

### **How It Works (Conceptually)**

Each node of the list looks like:

```
| prev_pointer | data | next_pointer |
```

All nodes are linked together.
Insertion or deletion doesn’t require shifting elements — just pointer manipulation.

---

## **2. Syntax and Declaration**

### **Header:**

```cpp
#include <list>
```

### **Syntax:**

```cpp
list<T> list_name;
```

* `T`: data type of elements.
* `list_name`: variable name of the list.

---

### **Example: Basic List Creation**

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> myList;          // Empty list

    myList.push_back(10);      // Insert at end
    myList.push_back(20);
    myList.push_front(5);      // Insert at front

    cout << "List elements: ";
    for (int n : myList) cout << n << " ";
}
```

**Output:**

```
List elements: 5 10 20
```

---

## **3. Internal Working**

Unlike `vector` (which uses contiguous array memory), `list` uses **heap-allocated nodes** linked by pointers.
That’s why:

* Insertion/deletion is **O(1)** (if position known).
* Random access like `myList[2]` is **not allowed** (requires traversal).

---

## **4. Core Operations on List**

We’ll now cover all important operations with code, explanation, and complexity.

---

### **1. Inserting Elements**

#### **Functions:**

* `push_front()` → insert at beginning
* `push_back()` → insert at end
* `insert(it, value)` → insert before position pointed by iterator

**Example:**

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {3, 2};

    l.push_back(5);          // at end
    l.push_front(1);         // at front

    auto it = l.begin();
    advance(it, 2);          // move iterator
    l.insert(it, 4);         // insert before 3rd position

    for (auto i : l) cout << i << " ";
}
```

**Output:**

```
1 3 4 2 5
```

**Complexity:**

* At front or back → `O(1)`
* At specific position → `O(n)` (to reach the iterator)

---

### **2. Accessing Elements**

#### **Functions:**

* `front()` → first element
* `back()` → last element
* Random access not supported, use `advance()` or `next()`.

**Example:**

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {1, 3, 4, 2, 5};

    cout << l.front() << endl;             // 1
    cout << l.back() << endl;              // 5

    cout << *next(l.begin(), 2);           // 3rd element
}
```

**Output:**

```
1
5
4
```

**Complexity:**
Accessing any element (except first or last) → `O(n)`

---

### **3. Updating Elements**

You can modify values using iterators.

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {1, 3, 4, 2, 5};

    l.front() = 11;               // change first
    auto it = l.begin();
    advance(it, 2);
    *it = 10;                     // update third element

    for (int i : l) cout << i << " ";
}
```

**Output:**

```
11 3 10 2 5
```

**Complexity:**
`O(1)` if iterator known, else `O(n)` to reach element.

---

### **4. Finding Elements**

Use **`std::find()`** from `<algorithm>`.

```cpp
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    list<int> l = {1, 3, 4, 2, 5};
    auto it = find(l.begin(), l.end(), 4);

    if (it != l.end())
        cout << "Found: " << *it;
    else
        cout << "Not Found";
}
```

**Output:**

```
Found: 4
```

**Complexity:**
`O(n)` — sequential traversal.

---

### **5. Traversing**

You can traverse using:

* **Iterators**
* **Range-based for loop**

```cpp
for (auto it = l.begin(); it != l.end(); ++it)
    cout << *it << " ";
```

or

```cpp
for (auto x : l) cout << x << " ";
```

**Output:**

```
1 3 4 2 5
```

**Complexity:** `O(n)`

---

### **6. Deleting Elements**

#### **Functions:**

* `pop_front()` → remove first
* `pop_back()` → remove last
* `erase(it)` → remove at specific iterator

**Example:**

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {1, 3, 4, 2, 5};

    l.pop_back();               // removes 5
    l.pop_front();              // removes 1

    auto it = l.begin();
    advance(it, 2);
    l.erase(it);                // remove 3rd remaining element

    for (auto i : l) cout << i << " ";
}
```

**Output:**

```
3 4
```

**Complexity:**
`O(1)` if iterator known, otherwise `O(n)` to locate position.

---

## **5. Other Important Member Functions**

| Function        | Description                            |
| --------------- | -------------------------------------- |
| `size()`        | Returns number of elements             |
| `empty()`       | Returns true if list is empty          |
| `rbegin()`      | Reverse iterator to last element       |
| `rend()`        | Reverse iterator before first          |
| `clear()`       | Removes all elements                   |
| `unique()`      | Removes consecutive duplicate elements |
| `remove(value)` | Removes all occurrences of value       |
| `sort()`        | Sorts the list                         |
| `reverse()`     | Reverses list order                    |
| `merge(list2)`  | Merges two sorted lists                |
| `swap(list2)`   | Swaps contents of two lists            |

---

## **6. Example Problem: Using Multiple Operations**

**Problem:**
Create a list, insert elements 1–6, remove even numbers, reverse the list, and display final elements.

**Solution:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {1, 2, 3, 4, 5, 6};

    l.remove_if([](int x){ return x % 2 == 0; });  // remove even
    l.reverse();                                   // reverse list

    for (int x : l) cout << x << " ";
}
```

**Output:**

```
5 3 1
```

---

## **7. Time Complexity Summary**

| Operation                 | Time Complexity   |
| ------------------------- | ----------------- |
| Insert (front/back)       | O(1)              |
| Delete (front/back)       | O(1)              |
| Insert/Delete at position | O(n)              |
| Access element            | O(n)              |
| Traversal                 | O(n)              |
| Sort / Reverse            | O(n log n) / O(n) |

---

## **8. Comparison — `list` vs `forward_list`**

| Feature            | `list`                  | `forward_list`           |
| ------------------ | ----------------------- | ------------------------ |
| Type               | Doubly linked list      | Singly linked list       |
| Traversal          | Both directions         | Forward only             |
| Memory             | Two pointers/node       | One pointer/node         |
| Random access      | Not supported           | Not supported            |
| `size()` available | Yes                     | No                       |
| Reverse iterators  | Supported               | Not supported            |
| Insertion/Deletion | Anywhere (before/after) | Only at/after a position |

---

## **9. Example: Advanced Use Case — Merge and Sort**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l1 = {1, 4, 3};
    list<int> l2 = {6, 2, 5};

    l1.sort();
    l2.sort();
    l1.merge(l2);       // merges sorted lists

    for (int x : l1) cout << x << " ";
}
```

**Output:**

```
1 2 3 4 5 6
```

---

## **10. Summary**

| Concept                | Explanation                             |
| ---------------------- | --------------------------------------- |
| **Container Type**     | Sequence container                      |
| **Data Structure**     | Doubly linked list                      |
| **Access**             | Sequential (no random access)           |
| **Insertion/Deletion** | O(1) when iterator known                |
| **Traversal**          | Bidirectional                           |
| **Best Use Case**      | Frequent insert/delete anywhere in list |
| **Header**             | `<list>`                                |

---

## **11. Reflection**

* Use **`list`** when:

  * You need **frequent insertions/deletions** in the middle.
  * Random access is **not needed**.
* Avoid it when:

  * You need **index-based access**.
  * You require **cache-friendly** performance (vectors perform better).

