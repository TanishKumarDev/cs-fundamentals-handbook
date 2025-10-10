# Operating Systems: Synchronization and Condition Variables

1. Synchronization Defined 📌

Definition: Synchronization in Operating Systems (OS) is the coordination of multiple processes or threads to ensure they access shared resources (e.g., variables, files, memory) in a controlled manner, preventing conflicts and ensuring data consistency. In a C++ program on Windows, synchronization ensures threads don’t interfere when modifying shared data.

Core Idea: Only one thread should access a shared resource at a time, like a single chef using a tawa (stove) to cook rotis, to avoid chaos in multi-threaded applications.

Details:

Shared Resources: Global variables (e.g., count), files, databases, or network sockets.

Without synchronization, concurrent access leads to race conditions and unpredictable results.

Critical for OS-managed apps like web servers, banking systems, or games on Windows.

The video builds on previous lectures, where single flag and Peterson’s solutions were discussed but had limitations (e.g., busy waiting or limited to two processes).

Analogy: Imagine a kitchen with one tawa. Two chefs (threads) want to cook rotis (access resource). Without a system, they fight over the tawa, ruining the rotis. Synchronization ensures one chef cooks at a time, keeping the kitchen smooth.

2. Real Scenario with Problems 🚨

Scenario: A C++ banking app on Windows manages a shared balance variable for a user’s account (initially $500). Two threads run:

Thread 1 (T1): Deposits $200.

Thread 2 (T2): Withdraws $100.

Expected Flow:

T1 reads balance ($500), adds $200, writes $700.

T2 reads balance ($700), subtracts $100, writes $600.

Problem (No Sync):

T1 reads balance ($500), prepares to add $200.

T2 reads balance ($500) before T1 writes, subtracts $100, writes $400.

T1 writes $700, but T2 overwrites with $400.

Result: Final balance is $400 instead of $600—deposit lost!

Issues:

Data Inconsistency: Uncontrolled access corrupts balance.

Financial Loss: User’s money vanishes, app loses trust.

Debugging Pain: Random thread scheduling makes errors hard to trace.

Context: Common in Windows apps—e.g., payroll systems, ticket booking, or inventory tools.

Video Context: The instructor uses a roti-cooking analogy: two chefs (T1, T2) try to use one tawa. Without coordination, both grab it, wasting time and burning rotis. Earlier solutions (like single flag) used busy waiting, where a chef keeps checking the tawa, wasting energy.

3. Critical Section Problem 🔍

Definition: The critical section problem occurs when multiple threads access a critical section—a code segment modifying a shared resource (e.g., balance in C++)—and need to execute exclusively to avoid data corruption.

Details:

Arises in multi-threaded C++ programs on Windows.

Without synchronization, threads cause race conditions, leading to inconsistent data.

The video mentions earlier solutions:

Single Flag: Flawed due to busy waiting and inefficiency.

Peterson’s Solution: Works for two threads but not scalable.

Goal: Ensure only one thread enters the critical section at a time.

Analogy: A single Aadhaar center counter (critical section) updates a database (shared resource). Multiple citizens (threads) try to update simultaneously, causing errors unless one goes at a time.

Impact: Corrupted data, crashes, or wrong outputs in C++ applications.

4. Race Condition ⚠️

Definition: A race condition occurs when multiple threads access and modify a shared resource concurrently, and the final outcome depends on the unpredictable order of execution by the OS (e.g., Windows scheduler).

Details:

Happens in critical sections without synchronization.

Timing-Sensitive: Windows schedules threads randomly, so results vary per run.

Example: Two threads increment count—if both read the same value, one update overwrites the other.

The video emphasizes that busy waiting in earlier solutions wasted CPU cycles, like a chef repeatedly checking the tawa.

Analogy: Two chefs race to add masala to a shared dish (resource). Both grab the same amount, but the last one to add overwrites the other’s effort, leaving the dish half-spiced!

Impact: Data corruption, financial errors, or app crashes in Windows C++ programs.

5. Thread Scheduling 🕒

Definition: Thread scheduling is the process by which the OS (e.g., Windows) decides which thread runs on the CPU, when, and for how long, using algorithms like round-robin or priority-based scheduling.

Details:

Purpose: Efficiently shares CPU time among multiple threads.

Mechanism: Windows uses time slices (e.g., 10ms), context switches, and thread priorities.

Challenge: Unpredictable order—Thread 1 may pause, letting Thread 2 run, causing race conditions in shared resources.

Link to Critical Section: Random scheduling triggers race conditions without synchronization.

The video implies that scheduling exacerbates busy waiting issues in older solutions.

Analogy: A kitchen manager (OS) juggles chefs (threads) cooking dishes. If they switch tasks mid-recipe without coordination, the dishes get mixed up!

Impact: Worsens data inconsistency in multi-threaded C++ apps.

6. C++ Code: Data Inconsistency Demo 💻

Scenario: Two threads, Thread1 (T1) and Thread2 (T2), increment a shared count variable in a C++ program on Windows, demonstrating a race condition due to lack of synchronization.

Analogy: Two workers (threads) tally votes (count) on a whiteboard (shared resource) using a notepad (temp). Both read the same total, add 1, but one overwrites the other—votes lost!

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


Explanation:

Setup: count starts at 0. Each thread increments 10,000 times—expected total: 20,000.

Steps: count++ splits into: read count to temp, add 1, write back.

Issue: T1 reads count = 0, T2 reads count = 0, both compute temp = 1, T1 writes count = 1, T2 overwrites count = 1—many increments lost!

Result: Final count often < 20,000 (e.g., 12,345) due to race condition.

Run: Compile in Visual Studio; output varies per run due to scheduling.

Video Note: The instructor highlights that earlier solutions (e.g., single flag) caused similar issues due to busy waiting, wasting CPU cycles.

7. Condition Variables: A Better Solution 🚀

What?: A condition variable is a synchronization primitive in C++ that allows a thread to wait (sleep) until a specific condition is true and be woken up (signaled) when the condition is met, avoiding busy waiting.

Core Idea: Threads sleep instead of looping (busy waiting), freeing the CPU, like a chef waiting for a bell instead of checking the tawa repeatedly.

How It Works:

Used with a mutex (lock) to protect the critical section.

Two operations:

wait(): Releases the mutex, puts the thread to sleep, and waits for a signal. Reacquires the mutex upon waking.

signal(): Wakes one waiting thread, notifying it to check the condition.

The video introduces condition variables as an improvement over single flag and Peterson’s solutions, which either wasted CPU or were limited to two threads.

Analogy: A chef (thread) waits for a bell (signal) to use the tawa (resource). Instead of checking repeatedly, they nap, saving energy (CPU cycles).

Pros: Eliminates busy waiting, scalable for multiple threads, efficient for Windows apps. Cons: Requires careful condition checking to avoid spurious wake-ups.

8. C++ Code: Condition Variable Demo 💻

Scenario: Two threads, T1 and T2, share a resource (e.g., a tawa) in a C++ program on Windows. T1 waits if the resource is busy; T2 signals when done, using a condition variable.

Analogy: One chef (T1) waits for the tawa, napping until another chef (T2) rings a bell (signal) to say it’s free.

#include <windows.h>
#include <iostream>
#include <condition_variable>
#include <mutex>
using namespace std;

mutex mtx;                    // Mutex for synchronization
condition_variable cond;      // Condition variable
bool tawa_free = false;       // Resource state

DWORD WINAPI Thread1_Task1(LPVOID) {
    unique_lock<mutex> lock(mtx); // Acquire lock
    while (!tawa_free) {          // Check condition
        cout << "T1: Tawa busy, waiting...\n";
        cond.wait(lock);          // Wait, release lock, sleep
    }
    cout << "T1: Using tawa to cook roti!\n"; // Critical section
    tawa_free = false;            // Mark tawa busy
    lock.unlock();                // Release lock
    return 0;
}

DWORD WINAPI Thread2_Task2(LPVOID) {
    Sleep(1000);                  // Simulate work
    unique_lock<mutex> lock(mtx); // Acquire lock
    cout << "T2: Done using tawa!\n";
    tawa_free = true;             // Mark tawa free
    cond.notify_one();            // Signal one waiting thread
    lock.unlock();                // Release lock
    return 0;
}

int main() {
    HANDLE threads[2];
    threads[0] = CreateThread(NULL, 0, Thread1_Task1, NULL, 0, NULL);
    threads[1] = CreateThread(NULL, 0, Thread2_Task2, NULL, 0, NULL);
    WaitForMultipleObjects(2, threads, TRUE, INFINITE);
    CloseHandle(threads[0]);
    CloseHandle(threads[1]);
    cout << "Main: Done!\n";
    return 0;
}


Explanation:

Setup: tawa_free = false (tawa busy). T1 waits for tawa; T2 signals when done.

Steps:

T1 locks mutex, checks tawa_free = false, calls cond.wait(), releases mutex, sleeps.

T2 locks mutex, sets tawa_free = true, calls cond.notify_one(), releases mutex.

T1 wakes, reacquires mutex, checks tawa_free = true, uses tawa.

Result: T1 cooks only when tawa is free, no busy waiting.

Run: Compile in Visual Studio; T1 waits efficiently, then uses tawa.

Video Note: The instructor’s roti analogy matches this, emphasizing no CPU waste.

9. Multiple Resource Instances 🖨️

What?: Condition variables can manage multiple instances of a resource (e.g., 3 printers), allowing multiple threads to proceed if resources are available.

Scenario: A C++ app on Windows manages 3 printers. Threads wait if all printers are busy; a thread signals when a printer is freed.

Analogy: Three tawas in a kitchen. Chefs (threads) cook if a tawa is free; otherwise, they nap until a bell (signal) rings.

Code:

#include <windows.h>
#include <iostream>
#include <condition_variable>
#include <mutex>
using namespace std;

mutex mtx;
condition_variable cond;
int printers = 3; // Available printers

DWORD WINAPI Thread_Task(LPVOID id) {
    unique_lock<mutex> lock(mtx);
    while (printers == 0) {
        cout << "Thread " << (int)id << ": No printers, waiting...\n";
        cond.wait(lock);
    }
    printers--; // Use a printer
    cout << "Thread " << (int)id << ": Printing with printer!\n";
    lock.unlock();
    Sleep(1000); // Simulate printing
    lock.lock();
    printers++; // Return printer
    cout << "Thread " << (int)id << ": Done, printer free!\n";
    cond.notify_one(); // Signal waiting thread
    lock.unlock();
    return 0;
}

int main() {
    HANDLE threads[5];
    for (int i = 0; i < 5; i++) {
        threads[i] = CreateThread(NULL, 0, Thread_Task, (LPVOID)i, 0, NULL);
    }
    WaitForMultipleObjects(5, threads, TRUE, INFINITE);
    for (int i = 0; i < 5; i++) {
        CloseHandle(threads[i]);
    }
    cout << "Main: All done!\n";
    return 0;
}


Explanation:

Setup: printers = 3. Five threads compete for printers.

Steps:

Threads 0–2 lock mutex, see printers > 0, decrement printers, print.

Thread 3 sees printers = 0, waits via cond.wait().

Thread 0 finishes, increments printers, signals Thread 3.

Result: Up to 3 threads print simultaneously; others wait efficiently.

Run: Compile in Visual Studio; output shows coordinated printer use.

Video Note: The instructor mentions multiple resources (e.g., printers), solved without busy waiting.

ASCII Diagram:

Initial: [Printer1][Printer2][Printer3]
T0 uses: [T0      ][Printer2][Printer3]
T1 uses: [T0      ][T1      ][Printer3]
T2 uses: [T0      ][T1      ][T2      ]
T3 waits: [T0      ][T1      ][T2      ] (T3 blocked)
T0 done: [Printer1][T1      ][T2      ] (T3 wakes, uses Printer1)


10. Three Conditions for Critical Section Solution ✅

Requirements:

Mutual Exclusion: Only one thread in the critical section at a time.

Why?: Prevents data corruption (e.g., two threads changing balance).

Progress: If no thread is in the critical section, a waiting thread can enter—no unnecessary delays.

Why?: Ensures system efficiency; no thread blocks a free resource.

Bounded Waiting: A waiting thread gets access after a finite time—no infinite delay.

Why?: Guarantees fairness, prevents starvation.

Importance: Condition variables meet these conditions, unlike single flag (lacks progress) or Peterson’s (limited to two threads). Essential for robust C++ apps on Windows.

Video Note: The instructor references these conditions implicitly, noting that earlier solutions failed progress or scalability.

11. Q: Can We Use a Single Flag? ❓

Idea: Use a bool flag = false—Thread1 enters if flag is false, sets it true; Thread2 waits if true.

Attempt:

bool flag = false;
Thread1: if (!flag) { flag = true; count++; flag = false; }
Thread2: while (flag) { /* wait */ } flag = true; count++; flag = false;


Video Context: The instructor dismisses single flag due to inefficiencies like busy waiting.

12. Q: Why Does Single Flag Fail? ⚠️

Flaws:

No Mutual Exclusion: Both threads may see flag = false, enter simultaneously—race condition!

Progress Issue: If Thread1 sets flag = true and crashes, Thread2 waits forever.

No Bounded Waiting: One thread may hog the critical section, starving others.

Busy Waiting: Thread2 loops on flag, wasting CPU cycles.

Timing Risk: Checking/setting flag isn’t atomic—threads overlap.

Analogy: One light (flag) signals a bridge is free. Two cars (threads) see green, both cross, and crash—no exclusivity!

Video Note: The instructor calls single flag “not impressive” due to these issues.

13. Q: Solution Should Have Three Sections? 🛠️

Structure:

Entry Section: Code to request access—acquires mutex, checks conditions, or waits.

Example: unique_lock<mutex> lock(mtx); cond.wait(lock);

Critical Section: Code to access/modify shared resource—e.g., count++ or use tawa.

Protected zone, runs solo.

Exit Section: Code to release access—unlocks mutex, signals others.

Example: cond.notify_one(); lock.unlock();

Why?:

Entry ensures safe access.

Critical section protects data.

Exit frees resource, maintaining progress.

Example: Condition variable code above follows this structure. Video Note: The instructor’s pseudo-code implies this structure, with wait in entry and signal in exit.

14. Q: Bounded Waiting 🔄

Definition: Guarantees a thread waiting for the critical section enters within a finite time—no indefinite delay.

Details:

Need: Prevents starvation—e.g., Thread1 can’t hog the tawa forever.

How?: Condition variables ensure fairness via notify_one() or notify_all().

Test: If T1 waits while T2 uses the tawa, T1 gets a turn after T2 signals.

Importance: Ensures fairness in multi-threaded C++ apps on Windows.

Video Note: The instructor mentions bounded waiting in the context of efficient synchronization.

15. Another Solution: Peterson’s Solution 🔧

What?: A software-based solution for two threads to share a critical section safely in C++.

How It Works:

Variables:

bool flag[2]: Each thread sets its flag to true to show interest.

int turn: Indicates whose turn to enter (0 or 1).

Process:

Thread1: Sets flag[0] = true, turn = 1, waits if Thread2 wants in and has turn.

Thread2: Sets flag[1] = true, turn = 0, waits if Thread1 wants in and has turn.

Exit: Thread sets its flag to false.

Meets Conditions:

Mutual Exclusion: Only one enters.

Progress: Waiting thread enters if other exits.

Bounded Waiting: No infinite wait.

Code:

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


Explanation:

Each thread increments count 10,000 times—expected: 20,000.

Peterson’s ensures one thread at a time—correct final value.

Run in Visual Studio; count hits 20,000 reliably.

Video Note: The instructor notes Peterson’s is limited to two threads, hence condition variables are better.

16. Disadvantages of Locks ⚠️

Issues:

Deadlock: Threads get stuck, each waiting for the other’s lock.

Infinite Wait: If a thread crashes holding a lock, others block forever.

Overhead: Locking/unlocking consumes CPU, slows C++ programs.

Complexity: Mismanaging locks causes bugs.

Video Note: The instructor warns of lock contention, where threads compete, slowing the system.

Impact: C++ apps on Windows lag, crash, or freeze—bad for games or servers.

17. Deadlock 😱

Definition: A deadlock occurs when two or more threads hold resources and wait for each other to release, causing all to block indefinitely.

Conditions:

Mutual Exclusion: Resources (e.g., locks) held exclusively.

Hold and Wait: Thread holds one resource, waits for another.

No Preemption: Resources can’t be forcibly taken.

Circular Wait: Threads form a loop, each waiting for the next.

Example:

Scenario: C++ app, two threads, two locks (Lock A: file, Lock B: printer).

T1 locks A, needs B to print.

T2 locks B, needs A to write.

T1 waits for B, T2 waits for A—deadlock!

Mermaid Diagram:

graph TD
    T1[Thread T1] -->|Holds| A[Lock A]
    T1 -->|Waits for| B[Lock B]
    T2[Thread T2] -->|Holds| B
    T2 -->|Waits for| A


Impact: App freezes—e.g., banking system stalls. Video Note: The instructor mentions lock-related deadlocks, to be covered later.

18. Debugging Issues 🐞

Challenges:

Randomness: Race conditions depend on scheduling—bugs appear inconsistently.

Timing: Errors shift when adding logs or Sleep.

Complexity: Tracking shared data in C++ is tough.

Video Note: The instructor emphasizes debugging challenges with busy waiting.

Strategies:

Use Visual Studio debugger, watch variables like count.

Add synced logs to trace thread order.

Stress-test with multiple threads.

Impact: Bugs in Windows apps hide, frustrating developers.

19. Sequential Execution 📏

What?: Running threads one after another, not concurrently—no critical section issues.

Pros:

Safe: No race conditions, data consistent.

Simple: Easier to code/debug in C++.

Cons:

Slow: No parallelism—wastes CPU on multi-core Windows systems.

Inefficient: Threads wait, delaying tasks.

Video Note: Implied as a fallback but not practical for performance.

Use: Okay for simple apps, bad for servers or games.

20. Starvation 😞

Definition: A thread is perpetually denied access to the critical section due to unfair scheduling or lock priority.

Details:

Cause: One thread hogs locks, or high-priority threads block others.

Example: T1 locks mutex repeatedly; T2 waits forever.

Impact: T2 starves—e.g., a user request in a Windows server never processes.

Fix:

Bounded waiting via condition variables.

Fair scheduling or priority adjustments.

Video Note: The instructor hints at starvation in lock contention.

Analogy: A hungry chef (thread) waits for the tawa, but others keep cutting in—never cooks!

21. Key Takeaways 🎯

Critical Section: Protect shared resources in C++—one thread at a time.

Race Condition: Uncontrolled access, random results.

Condition Variables: Eliminate busy waiting, scalable, efficient for Windows apps.

Solutions: Single flag (flawed), Peterson’s (two threads), condition variables (best).

Risks: Deadlock, starvation, debugging woes—code carefully.

Practice: Code in Visual Studio, test condition variables, fix race conditions!
