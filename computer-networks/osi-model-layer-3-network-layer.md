# 🌍 Network Layer (Problem-Solving Deep Dive)

---

## ❓ Why Network Layer?

Imagine you’re sending a WhatsApp message. You know **which app** (Transport Layer solved that). But now:

* How do you **find the right device** on the Internet?
* How do you **route data across multiple networks** (ISP routers, backbone, destination network)?

👉 That’s the job of the **Network Layer**.

---

# 1️⃣ IP Addressing

---

## 🔹 Classful Network Addressing

### ❓ Problem:

Early Internet needed a simple way to divide addresses into **network** and **host** parts.

### ✅ Solution: Classes (A, B, C, D, E)

| Class | First Bits | Range                       | Default Mask   | Networks  | Hosts/Network | Use         |
| ----- | ---------- | --------------------------- | -------------- | --------- | ------------- | ----------- |
| A     | 0          | 0.0.0.0 – 127.255.255.255   | /8 (255.0.0.0) | 128       | 16M           | Big Orgs    |
| B     | 10         | 128.0.0.0 – 191.255.255.255 | /16            | 16K       | 65K           | Medium Orgs |
| C     | 110        | 192.0.0.0 – 223.255.255.255 | /24            | 2M        | 254           | Small Orgs  |
| D     | 1110       | 224.0.0.0 – 239.255.255.255 | -              | Multicast | -             | Multicast   |
| E     | 1111       | 240.0.0.0 – 255.255.255.255 | -              | Reserved  | -             | Research    |

### ⚙️ Problem Example:

IP = `192.168.1.5` → Class C → Network = `192.168.1.0`, Host range = `1–254`.

---

## 🔹 Classless Addressing (CIDR)

### ❓ Problem with Classful:

Wasted IPs (ex: Class B gives 65K hosts, but company may need only 1000).

### ✅ CIDR (Classless Inter-Domain Routing):

* Represented as **IP/PrefixLength** (e.g., `192.168.1.0/27`).
* Prefix tells **how many bits are network**; rest are host.

👉 Example: `/27` → 32–27 = 5 bits for host → `2^5 – 2 = 30` hosts.

---

## 🔹 IPv4 Header Format (20–60 bytes)

| Field                                    | Why It Exists (Problem Solved)  |
| ---------------------------------------- | ------------------------------- |
| Version                                  | Tells if IPv4 or IPv6           |
| IHL                                      | Header length (variable)        |
| DSCP/ECN                                 | Quality of Service / Congestion |
| Total Length                             | Size of packet                  |
| Identification + Flags + Fragment Offset | Handle fragmentation            |
| TTL                                      | Prevent infinite looping        |
| Protocol                                 | Next Layer (TCP=6, UDP=17)      |
| Header Checksum                          | Error detection                 |
| Src/Dest IP                              | Addressing                      |

---

## 🔹 IPv4 vs IPv6

### ❓ Problems with IPv4:

* Limited addresses (32-bit → \~4.3B).
* NAT needed → breaks true end-to-end.
* No built-in security.

### ✅ IPv6 Fixes:

* 128-bit (virtually unlimited).
* Simplified header.
* Built-in IPsec.
* No NAT needed.
* Auto-configuration.

---

## 🔹 Private vs Public IP

* **Private IPs** (not routable on Internet):

  * Class A: `10.0.0.0 – 10.255.255.255`
  * Class B: `172.16.0.0 – 172.31.255.255`
  * Class C: `192.168.0.0 – 192.168.255.255`

* **Public IPs** → Routable on Internet, assigned by ISP.

---

# 2️⃣ Subnetting

---

## 🔹 Why Subnetting?

* Divide one large network into smaller ones.
* Save IPs, improve security, reduce broadcast traffic.

---

## 🔹 Subnet Masks

* Mask decides **Network vs Host bits**.
* Example: `192.168.1.0/26` → Mask = `255.255.255.192`

```
11111111.11111111.11111111.11000000
```

Network bits = 26, Host bits = 6 → 2^6 – 2 = **62 hosts**.

---

## 🔹 Calculate Network, Broadcast, Host Range

Example: `192.168.1.130/26`

* Mask: `/26` → Block size = 64.
* Subnets: `192.168.1.0, 192.168.1.64, 192.168.1.128, 192.168.1.192`.
* IP `192.168.1.130` lies in subnet `192.168.1.128/26`.
* Network Address: `192.168.1.128`.
* Broadcast Address: `192.168.1.191`.
* Host Range: `129–190`.

---

## 🔹 VLSM (Variable Length Subnet Masking)

* Assign different mask sizes for efficiency.
* Example: You have `/24` (256 hosts) and need:

  * Subnet A: 100 hosts → use `/25` (128 hosts).
  * Subnet B: 50 hosts → use `/26` (64 hosts).
  * Subnet C: 20 hosts → use `/27` (32 hosts).
    ✅ Saves addresses vs fixed classful.

---

## 🔹 Supernetting

* Opposite of subnetting: Combine smaller networks into one bigger network.
* Used by ISPs for route aggregation.
* Example: `192.168.0.0/24 + 192.168.1.0/24` → `192.168.0.0/23`.

---

# 3️⃣ Routing

---

## 🔹 What is Routing?

Process of selecting path for packets.

* Router = GPS for data.

---

## 🔹 Static vs Dynamic Routing

* **Static:** Manually configured, good for small networks.
* **Dynamic:** Routers exchange info automatically.

---

## 🔹 Routing Algorithms

### 1. **Distance Vector**

* Routers share “distance” (hops) to destinations.
* Simple, but can cause slow convergence.
* Example: RIP.

### 2. **Link State**

* Each router knows full topology.
* Faster convergence, more memory needed.
* Example: OSPF, IS-IS.

---

## 🔹 NAT (Network Address Translation)

### ❓ Problem:

IPv4 shortage.

### ✅ Solution:

Map multiple private IPs → one public IP.

* **Static NAT**: One-to-one.
* **Dynamic NAT**: Pool of public IPs.
* **PAT (Port Address Translation)**: Many private IPs share one public IP (most common).

---

# 4️⃣ Network Layer Protocols

---

## 🔹 ARP (Address Resolution Protocol)

* Map IP → MAC.
* Example: “Who has 192.168.1.10? Tell 192.168.1.1”.

---

## 🔹 RARP (Reverse ARP)

* Old protocol: MAC → IP. (Now replaced by DHCP).

---

## 🔹 DHCP (Dynamic Host Configuration Protocol)

* Assigns IPs dynamically.
* Process: **DORA**

  * Discover → Offer → Request → Acknowledge.

---

## 🔹 ICMP (Internet Control Message Protocol)

* Error reporting & diagnostics.
* Example: `ping`, `traceroute`.

---

## 🔹 IGMP (Internet Group Management Protocol)

* Manages multicast groups.
* Example: IPTV streaming.

---

## 🔹 RIP (Routing Information Protocol)

* Distance Vector, max hop = 15.
* Simple, outdated.

---

## 🔹 OSPF (Open Shortest Path First)

* Link state, Dijkstra’s algorithm.
* Fast convergence, widely used in enterprises.

---

## 🔹 IS-IS (Intermediate System to Intermediate System)

* Similar to OSPF, used in ISPs.

---

## 🔹 EIGRP (Enhanced Interior Gateway Routing Protocol)

* Hybrid (distance vector + link state).
* Cisco proprietary.

---

## 🔹 BGP (Border Gateway Protocol)

* “Routing protocol of the Internet.”
* Path vector protocol.
* Manages routing between ISPs (inter-AS).

---

## 🔹 MPLS (Multiprotocol Label Switching)

* Adds **labels** to packets for faster forwarding.
* Used in ISPs for VPNs, QoS.

---

## 🔹 GRE (Generic Routing Encapsulation)

* Tunneling protocol (encapsulate packets inside another).
* Example: VPNs.

---

# 📝 Reflection (Network Layer)

* **IP addressing = identifiers.**
* **Subnetting = resource optimization.**
* **Routing = choosing best path.**
* **Protocols = helpers (ARP, DHCP, ICMP, BGP, etc.).**

👉 Always ask:

* *Why do we need this concept?*
* *What problem does it solve?*
* *How does it actually work?*
