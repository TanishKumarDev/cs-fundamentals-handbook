# 🔗 Data Link Layer (Problem-Solving Deep Dive)

---

## ❓ Why Data Link Layer?

* Problem: **Two devices are directly connected (same LAN), but raw bits may get corrupted or lost.**
* Higher layers (Network/Transport) assume reliable links, but reality:

  * Signals can be corrupted by noise.
  * Frames can collide.
  * Devices may send faster than the receiver can handle.

✅ **Data Link Layer ensures:**

1. Reliable frame transfer between nodes.
2. Error detection & correction.
3. Flow control (avoid overwhelming receiver).
4. Proper addressing in LAN (MAC addresses).
5. Switching & segmentation of large networks (VLANs, link aggregation).

---

# 1️⃣ Switching Techniques

### ❓ Problem: Efficiently forward data in LAN.

#### 🔹 Types:

1. **Circuit Switching**

   * Dedicated path for duration of communication.
   * Example: Old telephone networks.
   * ✅ Reliable, but wasteful if idle.

2. **Message Switching**

   * Entire message stored & forwarded at each intermediate node.
   * ✅ No dedicated path, can queue if busy.

3. **Packet Switching**

   * Divide message into packets; each routed independently.
   * ✅ Efficient, used in Ethernet/IP networks.

---

# 2️⃣ Virtual LAN (VLAN)

### ❓ Problem: Logical separation of devices in same physical LAN.

* VLAN = logical LAN within physical LAN.
* Benefits:

  * Security (separate departments).
  * Broadcast control.
  * Flexible network design.

**Example:** HR & Finance on same switch, different VLAN IDs → cannot see each other directly.

---

# 3️⃣ Link Aggregation

### ❓ Problem: One link may be slow → bottleneck.

* Combine multiple physical links into one logical high-bandwidth link.
* Also provides redundancy: if one link fails, traffic still flows.
* Standard: IEEE 802.3ad (LACP).

**Example:** 4 × 1 Gbps links → 4 Gbps logical link.

---

# 4️⃣ Framing

### ❓ Problem: How to distinguish where one packet ends and another begins?

* **Framing:** Add headers/footers or delimiters.

#### Methods:

1. **Character Count** → count of bytes.

   * Problem: if count field corrupted → entire frame lost.

2. **Flag Bytes with Byte Stuffing** → special start/stop flags.

   * Example: HDLC uses `01111110`.
   * ✅ More reliable than count.

3. **Physical Layer Coding Violations** → detect pattern change to indicate boundary.

---

# 5️⃣ Error Detection

### ❓ Problem: Noise corrupts bits.

#### Methods:

1. **Parity Bit** → simple, 1-bit.

   * Can detect single-bit errors.

2. **Checksum** → sum of bytes modulo some number.

3. **Cyclic Redundancy Check (CRC)** → polynomial division.

   * Very reliable, detects burst errors.
   * Widely used in Ethernet, HDLC.

---

# 6️⃣ Error Correction

* Some codes allow **receiver to correct errors without retransmission**.
* Examples: **Hamming Code**, **Forward Error Correction (FEC)**.

✅ Useful in wireless, satellite, where retransmission is expensive.

---

# 7️⃣ Error Control

* Problem: Lost frames, corrupted frames.
* Solution: **Automatic Repeat reQuest (ARQ)**

### 🔹 Types:

1. **Stop-and-Wait ARQ**

   * Send one frame, wait for ACK.
   * ✅ Simple, but inefficient for high-latency links.
   * Throughput formula:

     $$
     \text{Efficiency} = \frac{T_f}{T_f + 2T_{prop}}
     $$

     Where $T_f$ = frame transmission time, $T_{prop}$ = propagation delay.

2. **Sliding Window Protocol**

   * Send multiple frames without waiting for ACK.

---

# 8️⃣ Sliding Window Protocols

### 🔹 Go-Back-N ARQ

* Send N frames in window.
* If an error detected → **go back** and retransmit all frames after error.
* ✅ Simple, but may waste bandwidth if errors frequent.

### 🔹 Selective Repeat ARQ

* Only **erroneous frames** are retransmitted.
* ✅ Efficient but requires more memory & logic.

---

# 9️⃣ Flow Control

### ❓ Problem: Sender faster than receiver.

* Sliding window = key technique.
* Receiver advertises window size → sender adapts speed.

---

# 🔹 Piggybacking

* Optimization: combine **ACK of previous frame** with **data frame** going in opposite direction.
* Reduces unnecessary frames.
* Example: in full-duplex Ethernet, two nodes exchange data + ACK in single frame.

---

# 📝 Reflection (Data Link Layer)

* **Switching & VLANs** → efficient LAN organization.
* **Framing** → divide bit stream into logical frames.
* **Error detection/correction & ARQ** → reliability.
* **Flow control & piggybacking** → efficiency.

✅ Problem-solving mindset:

* High error environment → use **CRC + Selective Repeat**.
* High-latency environment → **Sliding Window > Stop-and-Wait**.
* Limited bandwidth → **Piggybacking + Link Aggregation**.
