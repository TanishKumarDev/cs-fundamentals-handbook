# Process Scheduling Algo

## 1. Overview of Process Scheduling

![Process State Diagram](https://cdn.hashnode.com/res/hashnode/image/upload/v1749394196349/7584d576-3ae8-4a3a-a75a-66fd29d9b157.png)

**Process scheduling** is how the operating system (OS) allocates the CPU to processes (e.g., apps like a browser or game). It’s like a restaurant waiter (scheduler) deciding which customer (process) gets a table (CPU) based on a **scheduling algorithm**.

---

## 2. Key Terms in Process Scheduling

- **Arrival Time (AT)**: When a process enters the Ready Queue.
- **Burst Time (BT)**: Total CPU time a process needs to complete.
- **Completion Time (CT)**: When a process finishes execution.
- **Turnaround Time (TAT)**: Time from arrival to completion (TAT = CT - AT).
- **Waiting Time (WT)**: Time spent waiting in the Ready Queue (WT = TAT - BT).
- **Response Time**: Time from arrival to first CPU execution.
- **Throughput**: Number of processes completed per unit time.

---

## 3. Types of Scheduling Algorithms

### A. Non-Preemptive Scheduling
- **Definition**: A process keeps the CPU until it finishes or enters the Waiting state (e.g., for I/O). Like a customer who stays at a table until they’re done eating or step out.
- **Characteristics**: No interruptions unless the process yields the CPU.
- **Downside**: Risks **starvation**, where other processes wait excessively if one hogs the CPU.

### B. Preemptive Scheduling
- **Definition**: The OS interrupts a process if its **time quantum** (fixed time slot) expires, returning it to the Ready Queue. Like a restaurant limiting table time to ensure fairness.
- **Characteristics**: Time-sharing reduces starvation by giving each process a turn.
- **Advantage**: Fairer CPU allocation.

### Comparison
| **Feature** | **Non-Preemptive** | **Preemptive** |
|-------------|--------------------|----------------|
| **Starvation** | High (long processes dominate) | Low (time-sharing ensures turns) |
| **CPU Utilization** | Lower (fewer processes run) | Higher (more processes get CPU) |
| **Overhead** | Lower (fewer switches) | Higher (frequent context switches) |

- **Starvation Example**: In non-preemptive mode, a 30-minute video rendering task delays a browser, causing lag.
- **Preemptive Overhead**: Frequent context switches (e.g., every second) add OS overhead, like a waiter rearranging tables often.

---

## 4. Goals of CPU Scheduling
1. **Maximize CPU Utilization**: Keep the CPU busy, like filling all restaurant tables.
2. **Minimize Turnaround Time (TAT)**: Complete processes quickly, like serving customers fast.
3. **Minimize Waiting Time (WT)**: Reduce queue wait times, like shortening customer lines.
4. **Minimize Response Time**: Ensure quick initial CPU access, like greeting customers promptly.
5. **Maximize Throughput**: Complete many processes per unit time, like serving multiple customers in an hour.

---

## 5. First-Come-First-Serve (FCFS) Scheduling

### What Is It?
FCFS is the simplest algorithm, processing tasks in the order they arrive in the Ready Queue, like a ticket counter line. The **Short-Term Scheduler (STS)** assigns the CPU to the first process.

- **Type**: Non-preemptive (process runs until completion or I/O wait).
- **Operation**: Processes execute in arrival order (P1, P2, P3).

### Example
| **Process** | **Arrival Time (AT)** | **Burst Time (BT)** |
|-------------|-----------------------|---------------------|
| P1          | 0s                    | 20s                 |
| P2          | 1s                    | 2s                  |
| P3          | 2s                    | 2s                  |

**Gantt Chart**:
```cpp
| P1 (0-20) | P2 (20-22) | P3 (22-24) |
```

- **Completion Time (CT)**: P1: 20s, P2: 22s, P3: 24s
- **Turnaround Time (TAT = CT - AT)**: P1: 20s, P2: 21s, P3: 22s
- **Waiting Time (WT = TAT - BT)**: P1: 0s, P2: 19s, P3: 20s
- **Average Waiting Time**: (0 + 19 + 20) / 3 = **13s**

---

## 6. The Convoy Effect

![Convoy Effect](https://media.geeksforgeeks.org/wp-content/uploads/20231128113716/222-2-660.png)

### What Is It?
The **Convoy Effect** occurs in FCFS when a process with a long burst time (e.g., P1’s 20s) delays others, increasing average waiting time. It’s like a slow customer holding up a coffee shop line.

### Why Does It Happen?
FCFS executes processes in arrival order. A long-running process (e.g., video editing) blocks shorter tasks (e.g., opening a file), inflating waiting times.

### Example with Mitigation
Reordering to run shorter tasks first:
| **Process** | **Arrival Time (AT)** | **Burst Time (BT)** |
|-------------|-----------------------|---------------------|
| P2          | 1s                    | 2s                  |
| P3          | 2s                    | 2s                  |
| P1          | 0s                    | 20s                 |

**Gantt Chart**:
```cpp
| P2 (1-3) | P3 (3-5) | P1 (5-25) |
```

- **Completion Time (CT)**: P2: 3s, P3: 5s, P1: 25s
- **Turnaround Time (TAT)**: P2: 2s, P3: 3s, P1: 25s
- **Waiting Time (WT)**: P2: 0s, P3: 1s, P1: 5s
- **Average Waiting Time**: (0 + 1 + 5) / 3 = **2s**

**Observation**: Prioritizing shorter tasks reduces average waiting time from 13s to 2s, mitigating the Convoy Effect.

### Definition
The Convoy Effect is when a high-burst-time process in FCFS delays others, increasing waiting times. It applies to any resource (e.g., CPU, printer) hogged by one process.

### Why Is It a Problem?
- **Inefficient Resource Use**: Delays short tasks, slowing the system.
- **Increased Waiting Time**: Causes starvation for other processes.
- **Solution**: Use algorithms like **Shortest Job First (SJF)** or preemptive scheduling (e.g., Round Robin) to prioritize shorter tasks.

---

## 7. Shortest Job First (SJF) Scheduling

### Purpose
SJF prioritizes processes with the shortest burst time (BT) to minimize average waiting time, like a chef cooking quick orders (e.g., toast) before slow ones (e.g., pizza).

### Operation
- **Non-Preemptive**: Runs the shortest-BT process to completion or I/O wait.
- **Preemptive (SRTF)**: Preempts the current process if a new process has a shorter remaining BT.

### Example
| **Process** | **Arrival Time (AT)** | **Burst Time (BT)** |
|-------------|-----------------------|---------------------|
| P1          | 0s                    | 8s                  |
| P2          | 1s                    | 4s                  |
| P3          | 2s                    | 9s                  |
| P4          | 3s                    | 5s                  |

#### Non-Preemptive SJF
**Gantt Chart**:
```cpp
| P1 (0-8) | P2 (8-12) | P4 (12-17) | P3 (17-26) |
```

- **Completion Time (CT)**: P1: 8s, P2: 12s, P3: 26s, P4: 17s
- **Turnaround Time (TAT)**: P1: 8s, P2: 11s, P3: 24s, P4: 14s
- **Waiting Time (WT)**: P1: 0s, P2: 7s, P3: 15s, P4: 9s
- **Average Waiting Time**: (0 + 7 + 15 + 9) / 4 = **7.75s**

#### Preemptive SJF (SRTF)
**Gantt Chart**:
```cpp
| P1 (0-1) | P2 (1-5) | P4 (5-10) | P1 (10-17) | P3 (17-26) |
```

- **Completion Time (CT)**: P1: 17s, P2: 5s, P3: 26s, P4: 10s
- **Turnaround Time (TAT)**: P1: 17s, P2: 4s, P3: 24s, P4: 7s
- **Waiting Time (WT)**: P1: 9s, P2: 0s, P3: 15s, P4: 2s
- **Average Waiting Time**: (9 + 0 + 15 + 2) / 4 = **6.5s**

### Benefits
- Reduces average waiting time compared to FCFS (6.5s vs. 13s).
- Preemptive SJF (SRTF) avoids the Convoy Effect by prioritizing shorter tasks.

### Drawbacks
- **BT Estimation**: Hard to predict burst times due to variable code execution (e.g., loops, I/O).
- **Non-Preemptive Convoy Effect**: Long tasks delay others if they start first.
- **Starvation**: Long tasks may wait indefinitely in preemptive mode if short tasks arrive continuously.

### Use Case
Ideal for **batch systems** with predictable burst times (e.g., data processing).

---

## 8. Priority Scheduling

### Purpose
Assigns a priority to each process; higher-priority processes run first, like a hospital prioritizing critical patients over routine cases.

### Operation
- **Non-Preemptive**: Runs the highest-priority process to completion or I/O wait.
- **Preemptive**: Preempts the current process if a higher-priority one arrives.
- **Priority Basis**: Determined by importance (e.g., system tasks > user apps), not just BT.

### Example
| **Process** | **Arrival Time (AT)** | **Burst Time (BT)** | **Priority** |
|-------------|-----------------------|---------------------|--------------|
| P1          | 0s                    | 4s                  | 3            |
| P2          | 1s                    | 2s                  | 5            |
| P3          | 2s                    | 3s                  | 6            |
| P4          | 3s                    | 5s                  | 7            |
| P5          | 4s                    | 1s                  | 8            |
| P6          | 5s                    | 4s                  | 10           |
| P7          | 6s                    | 6s                  | 9            |

**Preemptive Gantt Chart** (higher number = higher priority):
```cpp
| P1 (0-1) | P2 (1-2) | P3 (2-3) | P4 (3-5) | P6 (5-9) | P4 (9-12) | P7 (12-18) | P5 (18-19) | P3 (19-21) | P2 (21-22) | P1 (22-25) |
```

- **Completion Time (CT)**: P1: 25s, P2: 22s, P3: 21s, P4: 12s, P5: 19s, P6: 9s, P7: 18s
- **Turnaround Time (TAT)**: P1: 25s, P2: 21s, P3: 19s, P4: 9s, P5: 15s, P6: 4s, P7: 12s
- **Waiting Time (WT)**: P1: 21s, P2: 19s, P3: 16s, P4: 4s, P5: 14s, P6: 0s, P7: 6s
- **Average Waiting Time**: (21 + 19 + 16 + 4 + 14 + 0 + 6) / 7 = **11.4s**

### Benefits
- Prioritizes critical tasks (e.g., system interrupts) for real-time systems.

### Drawbacks
- **Indefinite Waiting**: Low-priority processes may starve if high-priority ones dominate.
- **Convoy Effect**: High-priority processes can delay others.

### Solution
- **Aging**: Increase priority of waiting processes over time (e.g., +1 priority every 15s).

### Use Case
Best for **real-time systems** (e.g., medical devices, flight controls).

---

## 9. Round Robin (RR) Scheduling

### Purpose
Designed for **time-sharing systems**, RR ensures fairness by giving each process a fixed **time quantum (TQ)**, like students taking turns speaking for 2 minutes.

### Operation
- **Preemptive**: Processes run for a TQ (e.g., 2s). If unfinished, they return to the Ready Queue.
- **Criteria**: Based on arrival time and TQ, not BT.

### Example
| **Process** | **Arrival Time (AT)** | **Burst Time (BT)** |
|-------------|-----------------------|---------------------|
| P1          | 0s                    | 4s                  |
| P2          | 1s                    | 5s                  |
| P3          | 2s                    | 2s                  |
| P4          | 3s                    | 1s                  |
| P5          | 4s                    | 6s                  |
| P6          | 5s                    | 3s                  |

**Gantt Chart (TQ=2s)**:
```cpp
| P1 (0-2) | P2 (2-4) | P3 (4-6) | P1 (6-8) | P4 (8-9) | P5 (9-11) | P2 (11-13) | P6 (13-15) | P5 (15-17) | P2 (17-18) | P6 (18-19) | P5 (19-21) |
```

- **Completion Time (CT)**: P1: 8s, P2: 18s, P3: 6s, P4: 9s, P5: 21s, P6: 19s
- **Turnaround Time (TAT)**: P1: 8s, P2: 17s, P3: 4s, P4: 6s, P5: 17s, P6: 14s
- **Waiting Time (WT)**: P1: 4s, P2: 12s, P3: 2s, P4: 5s, P5: 11s, P6: 11s
- **Average Waiting Time**: (4 + 12 + 2 + 5 + 11 + 11) / 6 ≈ **7.5s**

### Benefits
- Eliminates starvation and Convoy Effect by ensuring all processes get CPU time.

### Drawbacks
- **Context-Switching Overhead**: Small TQ increases switches, slowing performance.
- **TQ Tuning**: Large TQ makes RR resemble FCFS, reducing fairness.

### Use Case
Ideal for **time-sharing systems** (e.g., Linux, Windows).

---

## 10. Multi-Level Queue (MLQ) Scheduling

### What Is It?
**Multi-Level Queue (MLQ)** scheduling divides processes into multiple queues based on type or priority (e.g., system, interactive, background), each with a specific algorithm (e.g., RR for system, FCFS for background). Higher-priority queues get CPU preference.

### Key Components
- **System Processes**: Critical tasks (e.g., kernel, drivers) with highest priority.
- **Interactive Processes**: User-facing apps (e.g., browsers) needing quick responses.
- **Background Processes**: Low-priority tasks (e.g., backups) running without user input.
- **CPU Allocation**: Prioritizes system > interactive > background.

### Why Is It Important?
- Ensures **system stability** by prioritizing critical tasks.
- Maintains **responsiveness** for interactive apps.
- Risks **starvation** for background tasks if high-priority queues dominate.

### How Does It Work?
- **Queues**: Separate queues for system (RR), interactive (RR), and background (FCFS).
- **Scheduling**: CPU prioritizes system queue, then interactive, then background.
- **Tools**: Windows APIs (`CreateThread`, `SetThreadPriority`) manage queues and priorities.

### Code Example
```cpp
#include <windows.h>
#include <iostream>
#include <queue>
using namespace std;

const int SYSTEM_QUANTUM = 10;  // ms
const int INTERACTIVE_QUANTUM = 20;
const int BACKGROUND_QUANTUM = 50;

struct Process {
    int id;
    string type; // system, interactive, background
    int burst_time;
};

queue<Process> system_q, interactive_q, background_q;

DWORD WINAPI Scheduler(LPVOID) {
    while (true) {
        if (!system_q.empty()) {
            Process p = system_q.front();
            system_q.pop();
            cout << "Running System Process " << p.id << " for " << SYSTEM_QUANTUM << "ms\n";
            p.burst_time -= SYSTEM_QUANTUM;
            Sleep(SYSTEM_QUANTUM);
            if (p.burst_time > 0) system_q.push(p);
        } else if (!interactive_q.empty()) {
            Process p = interactive_q.front();
            interactive_q.pop();
            cout << "Running Interactive Process " << p.id << " for " << INTERACTIVE_QUANTUM << "ms\n";
            p.burst_time -= INTERACTIVE_QUANTUM;
            Sleep(INTERACTIVE_QUANTUM);
            if (p.burst_time > 0) interactive_q.push(p);
        } else if (!background_q.empty()) {
            Process p = background_q.front();
            background_q.pop();
            cout << "Running Background Process " << p.id << " for " << BACKGROUND_QUANTUM << "ms\n";
            p.burst_time -= BACKGROUND_QUANTUM;
            Sleep(BACKGROUND_QUANTUM);
            if (p.burst_time > 0) background_q.push(p);
        } else {
            cout << "No processes to run\n";
            Sleep(100);
        }
    }
    return 0;
}

void addProcess(int id, string type, int burst_time) {
    Process p = {id, type, burst_time};
    if (type == "system") system_q.push(p);
    else if (type == "interactive") interactive_q.push(p);
    else background_q.push(p);
    cout << "Added Process " << id << " (" << type << ", burst: " << burst_time << "ms)\n";
}

int main() {
    addProcess(1, "system", 100);
    addProcess(2, "interactive", 200);
    addProcess(3, "background", 300);
    addProcess(4, "system", 150);
    addProcess(5, "interactive", 250);

    HANDLE scheduler = CreateThread(NULL, 0, Scheduler, NULL, 0, NULL);
    Sleep(10000);
    TerminateThread(scheduler, 0);
    CloseHandle(scheduler);
    cout << "Main: Done!\n";
    return 0;
}
```

### Example Scenario
- **Processes**: System (kernel, 100ms), interactive (browser, 200ms), background (backup, 300ms).
- **Result**: System tasks run first, interactive tasks follow, background tasks run last, reducing starvation but prioritizing critical tasks.

### Common Issues
- **Starvation**: Background queue may not run if system queue is busy. **Fix**: Allocate minimum CPU time to lower queues.
- **Queue Misplacement**: Interactive process in background queue. **Fix**: Use process type metadata.
- **No Preemption**: System tasks dominate. **Fix**: Use time quanta for fairness.

### Use Case
- **Windows Task Manager**: Prioritizes system processes (e.g., explorer.exe) over user apps and updates.
- **Servers**: Allocates CPU to critical tasks (e.g., network) over user queries and logs.

---

## 11. Multi-Level Feedback Queue (MLFQ) Scheduling

### What Is It?
**Multi-Level Feedback Queue (MLFQ)** enhances MLQ by allowing processes to move between queues based on behavior (e.g., CPU usage, I/O needs). It uses **aging** to prevent starvation, dynamically promoting or demoting processes.

### Why Is It Important?
- Reduces **starvation** by promoting waiting processes.
- Adapts to process behavior (e.g., interactive tasks stay in high-priority queues).
- Flexible for modern systems like Windows.

### How Does It Work?
- **Queues**: Multiple queues with different priorities (e.g., Q1: RR, high; Q2: RR, medium; Q3: FCFS, low).
- **Assignment**: New processes start in the highest-priority queue (Q1).
- **Demotion**: CPU-intensive processes move to lower queues if they exceed the time quantum.
- **Promotion (Aging)**: Waiting processes move to higher queues after a threshold (e.g., 100ms).
- **Tools**: Windows APIs (`SetThreadPriority`) for dynamic priority adjustments.

### Code Example
```cpp
#include <windows.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int NUM_QUEUES = 3;
const int QUANTA[NUM_QUEUES] = {10, 20, 50}; // ms
const int AGING_THRESHOLD = 100; // ms

struct Process {
    int id;
    string type;
    int burst_time;
    int priority; // 0 (highest), 1, 2 (lowest)
    int wait_time;
};

vector<queue<Process>> queues(NUM_QUEUES);

DWORD WINAPI Scheduler(LPVOID) {
    while (true) {
        bool ran = false;
        for (int i = 0; i < NUM_QUEUES; i++) {
            if (!queues[i].empty()) {
                Process p = queues[i].front();
                queues[i].pop();
                cout << "Running Process " << p.id << " (Priority " << p.priority << ") for " << QUANTA[i] << "ms\n";
                p.burst_time -= QUANTA[i];
                Sleep(QUANTA[i]);
                if (p.burst_time > 0 && p.priority < NUM_QUEUES - 1 && p.type != "interactive") {
                    p.priority++;
                    cout << "Demoted Process " << p.id << " to Priority " << p.priority << "\n";
                }
                if (p.burst_time > 0) queues[p.priority].push(p);
                ran = true;
                break;
            }
        }
        for (int i = 1; i < NUM_QUEUES; i++) {
            queue<Process> temp;
            while (!queues[i].empty()) {
                Process p = queues[i].front();
                queues[i].pop();
                p.wait_time += 10;
                if (p.wait_time >= AGING_THRESHOLD && p.priority > 0) {
                    p.priority--;
                    p.wait_time = 0;
                    cout << "Promoted Process " << p.id << " to Priority " << p.priority << "\n";
                }
                queues[p.priority].push(p);
            }
        }
        if (!ran) {
            cout << "No processes to run\n";
            Sleep(100);
        }
    }
    return 0;
}

void addProcess(int id, string type, int burst_time, int priority = 0) {
    Process p = {id, type, burst_time, priority, 0};
    queues[priority].push(p);
    cout << "Added Process " << id << " (" << type << ", Priority " << priority << ", burst: " << burst_time << "ms)\n";
}

int main() {
    addProcess(1, "system", 100, 0);
    addProcess(2, "interactive", 200, 0);
    addProcess(3, "background", 300, 2);
    addProcess(4, "system", 150, 0);
    addProcess(5, "interactive", 250, 0);

    HANDLE scheduler = CreateThread(NULL, 0, Scheduler, NULL, 0, NULL);
    Sleep(10000);
    TerminateThread(scheduler, 0);
    CloseHandle(scheduler);
    cout << "Main: Done!\n";
    return 0;
}
```

### Example Scenario
- **Processes**: P1 (system, 100ms, Q1), P2 (interactive, 200ms, Q1), P3 (background, 300ms, Q3).
- **Result**: P3 is promoted to Q2 if it waits too long, ensuring it runs eventually while maintaining responsiveness for P1 and P2.

### Benefits
- Adapts to process behavior, keeping interactive tasks responsive.
- Reduces starvation via aging.

### Drawbacks
- Complex implementation with multiple queues and dynamic movement.
- Overhead from frequent queue switches.

### Use Case
- **Windows OS**: Schedules explorer.exe (interactive) in high-priority queues, updates (background) in low-priority, with aging to prevent starvation.
- **Web Servers**: Prioritizes user requests over logs, promoting logs if they wait too long.

---

## 12. Comparison of Scheduling Algorithms

| **Algorithm** | **Pros** | **Cons** | **Starvation** | **Complexity** |
|---------------|----------|----------|----------------|----------------|
| **FCFS** | Simple, low overhead | Long waiting times, Convoy Effect | Possible | Low |
| **SJF** | Minimizes waiting time | Hard to predict BT, starvation for long tasks | High | Medium |
| **Priority** | Prioritizes critical tasks | Indefinite waiting for low-priority | High | Medium |
| **RR** | Fair, no starvation | High context-switching overhead with small TQ | Low | Medium |
| **MLQ** | Tailored to process types | Starvation in low-priority queues | High | High |
| **MLFQ** | Adaptive, reduces starvation | Complex implementation | Low (aging) | High |

---

## 13. Practical Implications

### Debugging Tools
| **Tool** | **Purpose** | **Example Command** |
|----------|-------------|---------------------|
| `top`/`htop` | Monitor CPU usage, priorities, states | `htop` |
| `ps` | View process details (PID, priority, state) | `ps -e -o pid,comm,priority,state` |
| `/proc/stat` | Check scheduling stats (e.g., context switches) | `cat /proc/stat` |

### Programming Best Practices
- **SJF**: Use a min-heap for shortest BT selection (O(log n)).
- **Priority Scheduling**: Use a priority queue with aging to prevent starvation.
- **RR**: Use a circular queue for the Ready Queue.
- **MLQ/MLFQ**: Use vectors/queues for dynamic queue management.

### System Administration
- **Tune TQ in RR**: Linux uses 10–100ms; adjust via kernel parameters.
- **Adjust Priorities**: Use `nice` or `renice` (e.g., `renice 10 <pid>`).
- **Swap Space**: Set to 1.5–2x RAM for MTS efficiency.

---

## 14. Connection to Previous Concepts

### Process States
- **FCFS**: Processes move from Ready to Running in arrival order, risking Convoy Effect.
- **SJF**: Prioritizes shortest BT, moving processes to Running or Waiting (I/O).
- **Priority**: High-priority processes move to Running; others wait.
- **RR**: Cycles processes between Ready and Running per TQ.
- **MLQ/MLFQ**: Manage processes across multiple queues, with MLFQ promoting/demoting based on behavior.

### Schedulers
- **Long-Term Scheduler (LTS)**: Admits processes to the Ready Queue.
- **Short-Term Scheduler (STS)**: Selects processes using FCFS, SJF, Priority, RR, MLQ, or MLFQ.
- **Medium-Term Scheduler (MTS)**: Swaps processes to manage memory, reducing Convoy Effect in MLQ/MLFQ.

### Convoy Effect
- **FCFS**: Severe due to long burst times.
- **SJF**: Non-preemptive mode risks it; preemptive avoids it.
- **Priority**: Possible if high-priority tasks dominate.
- **RR**: Eliminates it with time-sharing.
- **MLQ**: Risks it in low-priority queues.
- **MLFQ**: Mitigates it with aging.

### Orphan/Zombie Processes
- Poor scheduling (e.g., Priority or MLQ causing delays) can prevent parents from calling `wait()`, increasing zombies.

---

## 15. Kitchen Analogy: Scheduling Chefs

Imagine a kitchen where:
- **Orders** = Processes (e.g., sandwich, steak).
- **Stove** = CPU.
- **Chef** = Scheduler.

### FCFS Chef
- **Approach**: Cooks orders in arrival order.
- **Risk**: A long order (e.g., roast) delays others (Convoy Effect).
- **Example**: A diner chef cooking a 20-minute roast before a 2-minute coffee.

### SJF Chef
- **Approach**: Cooks quickest orders first (non-preemptive or preemptive).
- **Risk**: Hard to predict cooking times; long orders wait.
- **Example**: Prioritizes coffee (2min) over roast (20min).

### Priority Chef
- **Approach**: Cooks VIP orders first.
- **Risk**: Regular orders starve without aging.
- **Example**: Serves a celebrity’s steak before others.

### RR Chef
- **Approach**: Cooks each order for a fixed time (e.g., 2min), then rotates.
- **Risk**: Small TQ increases overhead (e.g., cleaning the stove).
- **Example**: Juggles multiple orders at a food truck.

### MLQ Chef
- **Approach**: Uses separate stations for VIP (system), customer (interactive), and staff (background) orders, with different cooking styles (RR, FCFS).
- **Risk**: Staff orders starve if VIPs dominate.
- **Example**: A restaurant prioritizing kitchen operations over cleaning tasks.

### MLFQ Chef
- **Approach**: Starts all orders at the VIP station; moves slow orders to lower stations, promotes waiting orders.
- **Risk**: Complex to manage multiple stations.
- **Example**: A smart chef adjusting order priority based on urgency and wait time.

---

## 16. Key Takeaways
- **FCFS**: Simple but prone to Convoy Effect.
- **SJF**: Minimizes waiting time but struggles with BT estimation and starvation.
- **Priority**: Prioritizes critical tasks but risks indefinite waiting; aging helps.
- **RR**: Fair, no starvation, ideal for time-sharing; TQ tuning critical.
- **MLQ**: Tailors scheduling to process types but risks starvation in low-priority queues.
- **MLFQ**: Adaptive, reduces starvation via aging, ideal for modern systems like Windows.
- **Goals**: Balance CPU utilization, waiting time, responsiveness, and throughput while minimizing starvation and overhead.
