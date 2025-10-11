# Critical Section in Operating Systems

## 1. Critical Section Defined

https://www.geeksforgeeks.org/operating-systems/critical-section-in-synchronization/

- **Definition**: A critical section is a segment of code in a C++ program where a thread accesses or modifies shared resources (e.g., variables, files, memory) and must execute without interference from other threads to avoid data corruption.
- **Core Idea**: Only one thread should enter this "protected zone" at a time to ensure data integrity in multi-threaded apps on Windows.
- **Details**:
    - Shared resources: Global variables (e.g., `count`), files, or network sockets.
    - Without control, concurrent access leads to unpredictable results.
    - Critical for OS-managed apps like servers, games, or banking systems.
- **Analogy**: A single-ticket booth at a theater—only one person (thread) buys a ticket (accesses resource) at a time, or chaos ensues (wrong seats assigned!).

## 2. Real Scenario with Problems

- **Scenario**: A C++ banking app on Windows manages a shared `balance` variable for a user’s account (initially $500). Two threads run:
    - Thread 1 (T1): Deposits $200.
    - Thread 2 (T2): Withdraws $100.
- **Expected Flow**:
    1. T1 reads balance ($500), adds $200, writes $700.
    2. T2 reads balance ($700), subtracts $100, writes $600.
- **Problem (No Sync)**:
    - T1 reads balance ($500), prepares to add $200.
    - T2 reads balance ($500) before T1 writes, subtracts $100, writes $400.
    - T1 writes $700, but T2 overwrites with $400.
    - **Result**: Final balance is $400 instead of $600—deposit lost!
- **Issues**:
    - **Data Inconsistency**: Uncontrolled access corrupts balance.
    - **Financial Loss**: User’s money vanishes, app loses trust.
    - **Debugging Pain**: Random timing makes errors hard to trace.
- **Context**: Common in Windows apps—e.g., payroll systems, ticket booking, or inventory tools.

## 3. Race Condition

https://www.geeksforgeeks.org/operating-systems/race-condition-vulnerability/

- **Definition**: A race condition occurs when multiple threads access and modify a shared resource simultaneously, and the final outcome depends on the unpredictable order of execution.
- **Details**:
    - Arises in critical sections without synchronization.
    - Timing-sensitive: OS schedules threads randomly, so results vary per run.
    - Example: Two threads increment `count`—if both read the same value, one update overwrites the other.
- **Impact**: Corrupted data, crashes, or wrong outputs in C++ programs.
- **Analogy**: Two runners (threads) race to paint a fence (shared resource) red or blue—both grab paint, but the last one to finish decides the color, unpredictably!

## 4. Thread Scheduling

- **Definition**: The OS (e.g., Windows) decides which thread runs on the CPU, when, and for how long, using scheduling algorithms (e.g., round-robin, priority-based).
- **Details**:
    - **Purpose**: Manages multiple threads to share CPU time efficiently.
    - **Mechanism**: Windows switches threads via time slices (e.g., 10ms), context switches, and priorities.
    - **Challenge**: Unpredictable order—Thread 1 may run, pause, then Thread 2 runs, messing up shared data.
    - **Link to Critical Section**: Random scheduling triggers race conditions if threads access shared resources without sync.
- **Analogy**: A chef (OS) juggles cooking multiple dishes (threads)—if they chop onions for two recipes at once without order, the dishes mix up!
- **Impact**: Worsens data issues in multi-threaded C++ apps.

## 5. C++ Code: Data Inconsistency Demo

- **Scenario**: Thread1 (Task1) and Thread2 (Task2) increment a shared `count` using `temp` in a C++ program on Windows, showing a race condition.
- **Analogy**: Two workers (threads) tally votes (`count`) on a whiteboard, using a notepad (`temp`). Both read the same total, add 1, but one overwrites the other—votes lost!

```cpp
#include <windows.h>
#include <iostream>
using namespace std;

int count = 0;  // Shared variable
int temp;       // Temp for computation

DWORD WINAPI Thread1_Task1(LPVOID) {
    for (int i = 0; i < 10000; i++) {
        temp = count;        // Read count
        temp = temp + 1;     // Increment temp
        Sleep(1);            // Simulate delay, mimic scheduling
        count = temp;        // Write back to count
    }
    cout << "Thread1: Done, count = " << count << "\n";
    return 0;
}

DWORD WINAPI Thread2_Task2(LPVOID) {
    for (int i = 0; i < 10000; i++) {
        temp = count;        // Read count
        temp = temp + 1;     // Increment temp
        Sleep(1);            // Simulate delay
        count = temp;        // Write back to count
    }
    cout << "Thread2: Done, count = " << count << "\n";
    return 0;
}

int main() {
    HANDLE threads[2];
    threads[0] = CreateThread(NULL, 0, Thread1_Task1, NULL, 0, NULL);
    threads[1] = CreateThread(NULL, 0, Thread2_Task2, NULL, 0, NULL);
    WaitForMultipleObjects(2, threads, TRUE, INFINITE);
    CloseHandle(threads[0]);
    CloseHandle(threads[1]);
    cout << "Final count: " << count << "\n";
    return 0;
}

```

- **Explanation**:
    - **Setup**: `count` starts at 0. Each thread increments 10,000 times—expect 20,000.
    - **Steps**: `count++` splits: read `count` to `temp`, add 1, write back.
    - **Issue**: T1 reads 0, T2 reads 0, both compute 1, T1 writes 1, T2 overwrites 1—many increments lost!
    - **Result**: Final `count` often < 20,000 (e.g., 12,345) due to race condition.
    - **Run**: Compile in Visual Studio; output varies per run due to scheduling.

## 6. How to Solve the Problem

- **Atomic Operations**:
    - **What?** Single, uninterruptible operations—no thread can interfere mid-step.
    - **How?** Windows provides `InterlockedIncrement(&count)`—increments `count` atomically.
    - **Pros**: Fast, simple for counters or flags.
    - **Cons**: Limited to basic ops (increment, decrement, compare-and-swap).
- **Mutual Exclusion**:
    - **What?** Ensures only one thread enters the critical section at a time.
    - **Core Idea**: Exclusivity prevents race conditions—other threads wait.
    - **Tools**: Locks, semaphores, etc., enforce this in C++.
- **Locks**:
    - **What?** Mechanisms like mutexes lock the critical section for one thread.
    - **How?** Use `CRITICAL_SECTION` in Windows:
        - `InitializeCriticalSection(&mutex)`: Sets up lock.
        - `EnterCriticalSection(&mutex)`: One thread enters, others block.
        - `LeaveCriticalSection(&mutex)`: Releases for next thread.
    - **Pros**: Reliable, widely used in C++ on Windows.
- **Semaphores**:
    - **What?** A counter tracking available resources (e.g., 1 for mutual exclusion).
    - **How?**
        - `CreateSemaphore(NULL, 1, 1, NULL)`: Init to 1 slot.
        - `WaitForSingleObject`: Decrements, blocks if 0.
        - `ReleaseSemaphore`: Increments, unblocks waiting thread.
    - **Pros**: Flexible—handles one or multiple resources (e.g., 3 printers).

## 7. Three Conditions for Critical Section Solution

- **Requirements**:
    1. **Mutual Exclusion**: Only one thread in the critical section—others wait outside.
        - Why? Prevents data corruption (e.g., two threads changing `count`).
    2. **Progress**: If no thread is in the critical section, a waiting thread can enter—no unnecessary delays.
        - Why? Ensures system moves forward, no thread blocks entry forever.
    3. **Bounded Waiting**: A waiting thread gets access after a finite time—no infinite delay.
        - Why? Guarantees fairness, prevents starvation.
- **Importance**: A good solution balances safety, efficiency, and fairness in C++ apps.

## 8. Q: Can We Use a Single Flag?

- **Idea**: Use a `bool flag = false`—Thread1 enters if `flag` is false, sets it true; Thread2 waits if true.
- **Attempt**:
    - Thread1: If `flag == false`, set `flag = true`, enter critical section.
    - Thread2: Waits if `flag == true`, enters when `false`.

## 9. Q: Why Does Single Flag Fail?

- **Flaws**:
    - **No Mutual Exclusion**: Both threads check `flag` at once, see `false`, both enter—race condition!
    - **Progress Issue**: If Thread1 sets `flag = true` and crashes, Thread2 waits forever—no progress.
    - **No Bounded Waiting**: One thread hogs critical section, others starve.
    - **Timing Risk**: Checking and setting `flag` isn’t atomic—threads overlap.
- **Analogy**: One light (flag) signals a bridge is free. Two cars (threads) see green, both cross, and crash—no exclusivity!

## 10. Q: Solution Should Have Three Sections?

- **Structure**:
    1. **Entry Section**: Code to request access—checks conditions, locks mutex, or waits.
        - Example: `EnterCriticalSection(&mutex)` or check flags.
    2. **Critical Section**: Code to access/modify shared resource—e.g., `count++`.
        - Protected zone, runs solo.
    3. **Exit Section**: Code to release access—unlocks mutex, signals others.
        - Example: `LeaveCriticalSection(&mutex)`.
- **Why?**:
    - Entry ensures safe access.
    - Critical section protects data.
    - Exit frees resource for others, maintaining progress.
- **Example**: Lock-based solution in C++—entry locks, critical section runs, exit unlocks.

## 11. Q: Bounded Waiting

- **Definition**: Guarantees a thread waiting for the critical section enters within a finite time—no indefinite delay.
- **Details**:
    - **Need**: Prevents starvation—e.g., Thread1 can’t lock forever, blocking Thread2.
    - **How?** Solutions like semaphores, fair scheduling, or Peterson’s algorithm limit wait.
    - **Test**: If Thread1 waits while Thread2 runs, Thread1 gets a turn after Thread2 exits.
- **Importance**: Ensures fairness in multi-threaded C++ apps on Windows.

## 12. Another Solution: Peterson’s Solution

- **What?** A software-based solution for two threads to safely share a critical section in C++.
- **How It Works**:
    - **Variables**:
        - `bool flag[2]`: Each thread sets its flag to true to show interest.
        - `int turn`: Indicates whose turn to enter (0 or 1).
    - **Process**:
        - Thread1: Sets `flag[0] = true`, `turn = 1`, waits if Thread2 wants in and has turn.
        - Thread2: Sets `flag[1] = true`, `turn = 0`, waits if Thread1 wants in and has turn.
        - Exit: Thread sets its flag to false.
    - **Meets Conditions**:
        - Mutual exclusion: Only one enters.
        - Progress: Waiting thread enters if other exits.
        - Bounded waiting: No infinite wait.
- **Code**:

```cpp
#include <windows.h>
#include <iostream>
using namespace std;

int count = 0;            // Shared resource
bool flag[2] = {false, false};  // Thread interest
int turn = 0;             // Whose turn?

DWORD WINAPI Thread1(LPVOID) {
    for (int i = 0; i < 10000; i++) {
        flag[0] = true;          // Entry: I want in
        turn = 1;                // Give turn to Thread2
        while (flag[1] && turn == 1)  // Wait if Thread2 wants & has turn
            Sleep(1);
        count++;                 // Critical Section: Increment
        flag[0] = false;         // Exit: I’m done
    }
    cout << "Thread1: Done, count = " << count << "\n";
    return 0;
}

DWORD WINAPI Thread2(LPVOID) {
    for (int i = 0; i < 10000; i++) {
        flag[1] = true;          // Entry: I want in
        turn = 0;                // Give turn to Thread1
        while (flag[0] && turn == 0)  // Wait if Thread1 wants & has turn
            Sleep(1);
        count++;                 // Critical Section: Increment
        flag[1] = false;         // Exit: I’m done
    }
    cout << "Thread2: Done, count = " << count << "\n";
    return 0;
}

int main() {
    HANDLE threads[2];
    threads[0] = CreateThread(NULL, 0, Thread1, NULL, 0, NULL);
    threads[1] = CreateThread(NULL, 0, Thread2, NULL, 0, NULL);
    WaitForMultipleObjects(2, threads, TRUE, INFINITE);
    CloseHandle(threads[0]);
    CloseHandle(threads[1]);
    cout << "Final count: " << count << "\n";
    return 0;
}

```

- **Explanation**:
    - Each thread increments `count` 10,000 times—expect 20,000.
    - Peterson’s ensures one thread at a time—correct final value.
    - Run in Visual Studio; `count` hits 20,000 reliably.

## 13. Disadvantages of Locks

- **Issues**:
    - **Deadlock**: Threads get stuck, each waiting for the other to release a resource.
    - **Infinite Wait**: Poor lock design (e.g., forgetting to unlock) blocks threads forever.
    - **Overhead**: Locking/unlocking consumes CPU, slows program.
    - **Complexity**: Mismanaging locks (e.g., wrong order) causes bugs.
- **Impact**: C++ apps on Windows lag, crash, or freeze—bad for games or servers.

## 14. Deadlock

- **Definition**: A situation where two or more threads hold resources and wait for each other to release, causing all to block indefinitely.
- **Situation**:
    - **Conditions**:
        1. **Mutual Exclusion**: Resources (e.g., locks) held exclusively.
        2. **Hold and Wait**: Thread holds one resource, waits for another.
        3. **No Preemption**: Resources can’t be forcibly taken—threads must release.
        4. **Circular Wait**: Threads form a loop, each waiting for the next.
- **Example**:
    - **Scenario**: C++ app, two threads, two resources (Lock A: file, Lock B: printer).
    - T1 locks A, needs B to print file.
    - T2 locks B, needs A to write file.
    - T1 waits for B, T2 waits for A—deadlock! Neither proceeds.
- **Impact**: App freezes—e.g., banking system stalls, users can’t transact.

## 15. Debugging Issues

- **Challenges**:
    - **Randomness**: Race conditions depend on thread scheduling—bugs appear inconsistently.
    - **Timing**: Errors vanish or shift when adding logs or delays (e.g., `cout` or `Sleep`).
    - **Complexity**: Tracking shared data across threads in C++ is tough.
- **Strategies**:
    - Use tools: Visual Studio debugger, watch variables like `count`.
    - Log safely: Add synced logs to trace thread order.
    - Test: Run multiple times, stress with many threads.
- **Impact**: Hard to fix—bugs in Windows apps hide, frustrate developers.

## 16. Sequential Execution

- **What?** Running threads one after another, not concurrently—no overlap, no critical section issues.
- **Pros**:
    - Safe: No race conditions, data stays consistent.
    - Simple: Easier to code, debug in C++.
- **Cons**:
    - Slow: No parallelism—wastes CPU in multi-core Windows systems.
    - Inefficient: Threads wait, delaying tasks like user input or network calls.
- **Use**: Okay for simple apps, bad for games or servers needing speed.

## 17. Starvation

- **Definition**: A thread is perpetually denied access to the critical section or resource due to unfair scheduling or lock priority.
- **Details**:
    - **Cause**: One thread hogs locks, or high-priority threads block lower ones.
    - **Example**: In C++ app, Thread1 locks mutex repeatedly, Thread2 waits forever.
    - **Impact**: Thread2 starves—e.g., a user request in a Windows server never processes.
- **Fix**:
    - Bounded waiting: Limit lock time.
    - Fairness: Use semaphores or priority adjustments.
- **Analogy**: A hungry guest (thread) waits for a table (resource), but others keep cutting in line—never eats!

## 18. Key Takeaways

- **Critical Section**: Protect shared resources in C++—one thread at a time.
- **Race Condition**: Uncontrolled access, random results.
- **Solutions**: Atomic ops, locks, semaphores, Peterson’s—meet mutual exclusion, progress, bounded waiting.
- **Risks**: Deadlock, starvation, debugging woes—plan carefully.
- **Practice**: Code in Visual Studio, test sync, fix race conditions!

---

A **critical section problem** occurs when multiple threads access and modify **shared resources** concurrently, leading to **race conditions**. A **race condition** happens when the program’s outcome depends on the **timing or interleaving** of thread execution.

---

## 🔐 What Is a Critical Section?

A **critical section** is a part of the program where the shared resource (e.g., variable, file, memory) is accessed. To avoid problems, only **one thread at a time** should execute in this section.

---

## 💥 Example of Race Condition (C++)

Below is a simple multithreaded example that shows a race condition:

### ❌ Without Mutex (Unsafe)

```cpp
#include <iostream>
#include <thread>

int counter = 0;

void increment() {
    for (int i = 0; i < 100000; ++i)
        ++counter; // Critical section
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final Counter Value: " << counter << std::endl;
    return 0;
}

```

### 🔎 What Happens?

Both threads modify `counter` at the same time. This causes a **race condition** and leads to **undefined behavior** (the result is usually < 200000).

---

## ✅ With Mutex (Safe)

Use `std::mutex` to protect the critical section.

```cpp
#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        mtx.lock();
        ++counter; // Critical section
        mtx.unlock();
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final Counter Value: " << counter << std::endl;
    return 0;
}

```

---

## ✅ Better with `std::lock_guard` (RAII)

```cpp
#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++counter;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final Counter Value: " << counter << std::endl;
    return 0;
}

```

---

## 📌 Key Concepts

| Term | Meaning |
| --- | --- |
| **Race Condition** | Multiple threads accessing shared data without proper synchronization |
| **Critical Section** | Code part accessing shared resources |
| **Mutex** | Mutual exclusion object to prevent concurrent access |
| **std::lock_guard** | Wrapper that automatically locks and unlocks a mutex (safer, RAII) |

---

## 🧠 Final Notes

- Use **mutexes** to protect critical sections.
- Prefer `std::lock_guard` or `std::unique_lock` for exception-safe locking.
- Be careful of **deadlocks** if multiple locks are involved.

---

Let’s **deeply explain** the C++ code that demonstrates the **critical section problem** and how to fix it using `std::mutex` and `std::lock_guard`. We'll break down each version step-by-step:

---

## 🧪 1. Code Without Mutex (Unsafe, Race Condition)

### ⚠️ Code

```cpp
#include <iostream>
#include <thread>

int counter = 0;

void increment() {
    for (int i = 0; i < 100000; ++i)
        ++counter; // Critical section
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final Counter Value: " << counter << std::endl;
    return 0;
}

```

---

### 🧩 Explanation

### `#include <iostream>`

Header for input/output operations (e.g., `std::cout`).

### `#include <thread>`

Allows creating and managing threads using `std::thread`.

### `int counter = 0;`

A **shared global variable** used by both threads. This is the **shared resource** and is in the **critical section**.

### `void increment()`

Function that increments `counter` **100000 times**.

⚠️ Since **both threads run this function**, they try to update `counter` at the same time.

```cpp
++counter;

```

This line looks simple, but it's **not atomic**. It involves:

1. Reading the current value of `counter`.
2. Incrementing it.
3. Writing the new value back.

➡️ When two threads do this **at the same time**, it causes a **race condition**.

---

### `main()` function:

```cpp
std::thread t1(increment);
std::thread t2(increment);

```

- Two threads (`t1` and `t2`) are started and both run the `increment()` function.
- **Both access the same** `counter` concurrently — that's the race condition.

```cpp
t1.join();
t2.join();

```

- Ensures `main()` waits for both threads to finish before printing the result.

```cpp
std::cout << "Final Counter Value: " << counter << std::endl;

```

- The expected value is `200000`, but due to **race condition**, it's usually **less**.

---

## ✅ 2. Code With Mutex (Safe)

### Code

```cpp
#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        mtx.lock();
        ++counter;
        mtx.unlock();
    }
}

```

---

### 🧩 Explanation

### `#include <mutex>`

Header for using **mutexes** — a mutual exclusion object.

### `std::mutex mtx;`

Creates a **mutex** named `mtx` to guard the critical section.

### In `increment()`:

```cpp
mtx.lock();
++counter;
mtx.unlock();

```

- `mtx.lock()` blocks the thread until it **acquires the lock** (i.e., no other thread is inside this critical section).
- Once it has the lock, it increments the `counter`.
- Then `mtx.unlock()` **releases the lock**, allowing other threads to enter.

✅ This **ensures only one thread modifies** `counter` at a time, fixing the race condition.

---

## ✅ 3. Code with `std::lock_guard` (Best Practice - RAII)

### Code

```cpp
#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++counter;
    }
}

```

---

### 🧩 Explanation

### `std::lock_guard<std::mutex> lock(mtx);`

This is a **RAII (Resource Acquisition Is Initialization)** wrapper for locking:

- When `lock` is created, it **automatically locks** `mtx`.
- When `lock` goes out of scope (end of `{}`), it **automatically unlocks** `mtx`.

✅ This ensures:

- Safe locking and unlocking even if **exceptions are thrown**.
- Cleaner and less error-prone code than manual `.lock()` and `.unlock()`.

---

## 🔁 Summary of Differences

| Version | Race Condition | Mutex Used? | Safe? | Best Practice? |
| --- | --- | --- | --- | --- |
| Without Mutex | ❌ Yes | ❌ No | ❌ No | ❌ No |
| With Manual Mutex | ✅ No | ✅ Yes | ✅ Yes | ⚠️ Needs manual care |
| With `lock_guard` | ✅ No | ✅ Yes | ✅ Yes | ✅ Yes (RAII) |

---

## 📌 Key Takeaways

- **Race conditions** occur when threads access shared data simultaneously without synchronization.
- **Mutex (**`std::mutex`) is used to **protect critical sections**.
- Prefer `std::lock_guard` for safety and cleaner code (handles unlocking automatically).
- Always think about **thread safety** when using shared data.

---