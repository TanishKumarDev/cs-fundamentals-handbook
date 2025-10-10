# Presentation Layer (Layer 6)

The **Presentation Layer** is like the “translator” of the OSI model. It ensures that data sent from one system is in a format the receiving system can understand.

👉 Think: Two people speak different languages → presentation layer is the **translator**.

### ✨ Services Provided by Presentation Layer

1. **Translation**

   * Converts data into a common format.
   * Example: EBCDIC ↔ ASCII, different image formats (JPEG, PNG).

2. **Encryption & Decryption**

   * Protects data during transmission.
   * Example: SSL/TLS for HTTPS, VPN tunneling.

3. **Compression & Decompression**

   * Reduces data size for faster transmission.
   * Example: MP3, JPEG, MPEG compression.

4. **Data Serialization**

   * Converts complex data structures into transmittable streams.
   * Example: JSON, XML encoding.

👉 **Real-World Example:**

* Watching Netflix → compression reduces bandwidth.
* HTTPS → encryption via SSL/TLS.
* Email attachments → MIME ensures compatibility.

---

# Protocols at Session & Presentation Layer

1. **Application Filing Protocol (AFP)**

   * Used in Apple networks for file services.
   * Works in **session layer** to manage file sharing.

2. **NetWare Core Protocol (NCP)**

   * Used by Novell NetWare OS for network resource sharing.
   * Handles **session and presentation tasks** like authentication.

3. **Secure Socket Layer (SSL) / TLS**

   * Provides **encryption, authentication, integrity**.
   * Works between session & presentation.
   * Basis of **HTTPS**.

4. **Remote Procedure Call (RPC)**

   * Allows a program to execute code on a remote machine.
   * Example: NFS (Network File System).

5. **Point-to-Point Tunneling Protocol (PPTP)**

   * Used in VPNs.
   * Encapsulates and encrypts data for secure transfer.

6. **Multipurpose Internet Mail Extensions (MIME)**

   * Standard for email attachments (images, docs, audio, video).
   * Ensures compatibility across different systems.

---

# 🛠️ How to Explain in an Interview

**Q: What’s the difference between Session and Presentation Layer?**
👉

* Session: Manages **who talks to whom, when, and for how long**.
* Presentation: Ensures **what is said is understood correctly** (format, encryption, compression).

**Q: Give a real-life analogy.**
👉

* Session Layer = **phone call management** (dial, connect, maintain, hang up).
* Presentation Layer = **translator & security guard** (translates language, encrypts data, compresses message).

**Q: Example protocols?**
👉

* Session Layer: RPC, PPTP, NetBIOS.
* Presentation Layer: SSL/TLS, MIME, AFP.

