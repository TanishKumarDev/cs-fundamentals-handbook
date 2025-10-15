# **Forward List in C++ STL**

## **1. Introduction**

### **What is a Forward List?**

A **forward list** in C++ STL represents a **singly linked list** — a data structure where each element (called a *node*) points to the next one in the sequence.
It provides **efficient insertion and deletion** at known positions but **does not support random access** (unlike arrays or vectors).

It was introduced in **C++11** to offer a **memory-efficient alternative** to `std::list`.

---

### **Why Use Forward List?**

* To store data **non-contiguously** in memory.
* When you need **fast insertions and deletions** but **don’t require backward traversal** or random access.
* Useful in **low-memory environments**, since it uses **only one pointer per node** (next pointer), unlike `list` which uses two.

---

### **How It Works**

Each node of a forward list contains:

```
| data | next_pointer |
```

The last node’s next pointer points to `nullptr`. Traversal is one-way — from head to tail.

---

## **2. Syntax & Declaration**

To use forward list, include the header:

```cpp
#include <forward_list>
```

Declaration syntax:

```cpp
forward_list<T> name;
```

Example:

```cpp
forward_list<int> fl;  // Forward list of integers
```

---

## **3. Initialization Methods**

You can initialize a forward list in multiple ways:

```cpp
#include <bits/stdc++.h>
using namespace std;

void printFL(forward_list<int>& fl) {
    for (auto i : fl) cout << i << " ";
    cout << '\n';
}

int main() {
    forward_list<int> fl1;               // Empty
    forward_list<int> fl2(3, 4);         // 3 elements, each = 4
    forward_list<int> fl3 = {1, 5, 3, 4}; // Initializer list

    printFL(fl2);
    printFL(fl3);
}
```

**Output:**

```
4 4 4
1 5 3 4
```

---

## **4. Core Operations**

Let’s go through the main operations you can perform with `forward_list`.

---

### **1. Accessing Elements**

* You cannot use indices like `fl[2]`.
* Use **iterators** or helper functions like `front()`, `next()`, or `advance()`.

Example:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    forward_list<int> fl = {1, 5, 3, 4};

    cout << fl.front() << endl;         // Access first
    auto it = next(fl.begin(), 2);      // Move iterator 2 steps ahead
    cout << *it;                        // Access 3rd element
}
```

**Output:**

```
1
3
```

---

### **2. Inserting Elements**

Use:

* `push_front()` → Insert at beginning (O(1))
* `insert_after(iterator, value)` → Insert after a given position (O(n))

Example:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    forward_list<int> fl = {5, 4};
    fl.push_front(1);                  // Insert at front
    auto it = fl.begin();
    advance(it, 1);
    fl.insert_after(it, 3);            // Insert 3 after 5

    for (auto x : fl) cout << x << " ";
}
```

**Output:**

```
1 5 3 4
```

---

### **3. Updating Elements**

Access via iterator and modify.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    forward_list<int> fl = {1, 5, 3, 4};

    fl.front() = 111;                // Update first element
    auto it = next(fl.begin(), 2);
    *it = 333;                       // Update 3rd element

    for (auto x : fl) cout << x << " ";
}
```

**Output:**

```
111 5 333 4
```

---

### **4. Searching Elements**

Use **`std::find()`** (from `<algorithm>`).

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    forward_list<int> fl = {1, 5, 3, 4};
    auto it = find(fl.begin(), fl.end(), 3);

    if (it != fl.end()) cout << "Found: " << *it;
    else cout << "Not found";
}
```

**Output:**

```
Found: 3
```

---

### **5. Traversing**

Forward traversal only.

```cpp
for (auto i : fl)
    cout << i << " ";
```

**Output:**

```
1 5 3 4
```

---

### **6. Deleting Elements**

* `pop_front()` → removes first element (O(1))
* `erase_after(it)` → removes element after given iterator (O(n))

Example:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    forward_list<int> fl = {1, 5, 3, 4};
    fl.pop_front();                  // Delete first
    auto it = fl.begin();
    advance(it, 1);
    fl.erase_after(it);              // Delete after 2nd position

    for (auto x : fl) cout << x << " ";
}
```

**Output:**

```
5 3
```

---

### **7. Checking Empty List**

```cpp
forward_list<int> fl;
if (fl.empty())
    cout << "Empty list\n";
fl.push_front(10);
if (!fl.empty())
    cout << "Not empty\n";
```

**Output:**

```
Empty list
Not empty
```

---

### **8. Finding Size**

`forward_list` has **no `size()` function**, since it’s singly linked.
Use **`std::distance()`** instead.

```cpp
forward_list<int> fl = {10, 20, 30, 40};
cout << distance(fl.begin(), fl.end());  // Output: 4
```

---

## **5. Time Complexity Summary**

| Operation                      | Time Complexity |
| ------------------------------ | --------------- |
| Access first element           | O(1)            |
| Access nth element             | O(n)            |
| Insert at front                | O(1)            |
| Insert after specific position | O(n)            |
| Delete first element           | O(1)            |
| Delete after specific position | O(n)            |
| Traversal                      | O(n)            |

---

## **6. Forward List vs List**

| Feature         | `forward_list`                              | `list`                                      |
| --------------- | ------------------------------------------- | ------------------------------------------- |
| Type            | Singly linked list                          | Doubly linked list                          |
| Traversal       | Forward only                                | Forward & backward                          |
| Memory          | Less (one pointer/node)                     | More (two pointers/node)                    |
| Insert/Delete   | Fast, only at/after position                | Fast anywhere                               |
| Extra Functions | Limited (no `size()`, no reverse iterators) | Full (supports `size()`, `reverse()`, etc.) |

---

## **7. Summary**

| Concept        | Explanation                                              |
| -------------- | -------------------------------------------------------- |
| **Header**     | `<forward_list>`                                         |
| **Nature**     | Singly linked list                                       |
| **Access**     | Sequential only                                          |
| **Memory**     | Lightweight                                              |
| **Best For**   | Frequent insertions/deletions at front or known position |
| **Limitation** | No backward traversal or random access                   |

---

## **8. Example Problem**

**Problem:**
Create a forward list of integers, insert numbers 1–5, remove all even numbers, and print the final list.

**Solution:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    forward_list<int> fl = {1, 2, 3, 4, 5};

    // Remove even numbers using lambda
    fl.remove_if([](int x){ return x % 2 == 0; });

    for (int i : fl) cout << i << " ";
}
```

**Output:**

```
1 3 5
```

---

## **9. Key Takeaways**

* `forward_list` = **optimized singly linked list** for **low memory** use.
* **Only forward traversal**, no random or backward access.
* Perfect for **queues, hash buckets**, or **stream-like operations**.
* Prefer `forward_list` over `list` when:

  * Memory efficiency matters.
  * Only forward traversal is needed.
  * Constant-time front insertions/deletions are required.

---