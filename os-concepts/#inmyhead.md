## 1. How does the OS handle priority inversion, and why can it be a critical problem in real-time systems?

* **Preemption = Jab ek higher priority process aata hai aur OS usko turant CPU de deta hai, chahe koi dusra process chal raha ho.**

### Priority Inversion Problem (step by step example)


* Low Priority Task (L) ne ek lock pakda hua hai.
Example: L ek file read kar raha hai, aur uske liye file lock le rakha hai.
    * High Priority Task (H) aaya aur usko bhi woh file chahiye.

* But woh wait karega, kyunki lock abhi L ke paas hai.

* Abhi OS sochta hai:

    * L toh low priority hai → thoda slow chalega.

    * Is beech mein ek Medium Priority Task (M) aaya.

    * Preemption rule ke hisaab se → M ko run kar diya (kyunki M > L).

### Why is this a critical problem in real-time systems?

* Real-time systems (e.g., spacecraft, medical devices, autonomous cars) rely on strict deadlines.

* If a high-priority task misses its deadline because of priority inversion:

* System failure may occur.
    
* Example:

    * NASA’s Mars Pathfinder mission (1997) experienced resets due to priority inversion in its software.

    * So, priority inversion breaks predictability—a fatal flaw in real-time systems.

### OS Solution

#### 1. Priority Inheritance Protocol (PIP)

* Jab L ke paas lock hai aur H wait kar raha hai, toh OS bolta hai:
“Ok L, tum abhi high priority ban jao (temporarily)!”

* Isse L turant complete karega aur lock chhod dega.

* H ko lock mil jaayega.

* Baad mein L apni original priority pe aa jaayega.

#### 2. Priority Ceiling Protocol (PCP)

* Har resource (jaise lock, kitchen, file, printer) ko ek maximum priority level assign hota hai.

* Agar tumhari priority us ceiling se kam hai, toh tum lock le hi nahi sakte.

* Matlab deadlock aur inversion dono avoid ho jaate hain.

## 2. Explain how context switching works at the kernel level and why it’s considered an expensive operation.

#### 1. What is Context Switching?

* CPU ek time pe sirf ek process run karta hai.
* Lekin OS ko multi-tasking dikhani hoti hai (multiple processes lagta hai saath chal rahe).
* Iske liye OS processes ke beech fast switch karta hai.
👉 Is switching = context switching.


#### 2. What Happens in Context Switch (Kernel level)?

When OS decides ki “current process (P1) ko rok kar dusra process (P2) chalana hai”:

1. **Save Current Process State (P1):**

    * Registers (R0…Rn)

    * Program Counter (PC → next instruction address)

    * Stack Pointer (SP)

    * CPU flags

        All stored in PCB (Process Control Block) of P1.

2. **Update Scheduling Queues:**

    * P1 ko ready/waiting queue mein daal do (status change).

    * Scheduler selects next process P2.

3. **Load Next Process (P2):**

    * P2 ka PCB uthao.

    * Restore registers, PC, SP, flags.

    * Now CPU execution continues from P2’s last saved instruction.

        👉 Matlab context switch = save old context + load new context.

### 3. Why Context Switching is Expensive?

Context switch ≠ free. Ye costly hai kyunki:

1. Multiple Memory Accesses:

    * Save/restore PCB values = memory read/write.

2. Pipeline Flush:

    * CPU ke andar instructions ek pipeline mein hote hain.

    * Switch karte hi pipeline clear karna padta hai → waste cycles.

3. TLB (Translation Lookaside Buffer) Flush:

    * New process ka virtual memory mapping alag hota hai.

    * TLB invalidate → page table lookups again → slowdown.

* Cache Misses:

    * CPU cache mein P1 ka data tha.

    * Ab P2 chal raha hai → uska data cache mein nahi → cache miss → slow memory fetch.

    *So, har switch mein kuch microseconds to milliseconds lag jaate hain.
    For real-time / high-throughput systems, ye bottleneck ban sakta hai.*

#### TLB

```
* TLB = Translation Lookaside Buffer
* Ek small, very fast cache hota hai inside CPU.
* Iska kaam: Virtual address → Physical address ka translation fast karna.

 ⚡Step by Step Example

1. Har modern OS Virtual Memory use karta hai.

    - Matlab process ko lagta hai uske paas apna continuous memory block hai (Virtual Address Space).

    - Lekin actually woh Physical RAM mein scattered hota hai.

2. Virtual → Physical translation hota hai Page Table ke through.

    - Ye page table memory mein hota hai → access slow ho jaata hai.

3. TLB = ek cache of page table entries

    - Jab tum ek address access karte ho, CPU pehle TLB check karta hai.

    - Agar entry mil gayi (TLB hit) → direct fast physical address.

    - Agar nahi mili (TLB miss) → OS ko memory mein page table dekhna padega (slow).
```