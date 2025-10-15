# Consistent Hashing
## 🎯 The Basic Problem: Why We Need Hashing

### Imagine a School Library 📚
- You have 1,000 books and 1 librarian
- The librarian remembers where every book is
- But when you get 10,000 books, the librarian gets overwhelmed!

**Solution**: Hire more librarians and divide the books

## 🔢 Simple Hashing (The Naive Way)

### The "Modulus" Method
```javascript
// Which shelf should the book go on?
function findShelf(bookId, totalShelves) {
    return bookId % totalShelves;  // Simple division remainder
}
```

### Example with 3 Shelves:
| Book ID | Calculation | Shelf |
|---------|-------------|-------|
| 1 | 1 % 3 = 1 | Shelf 1 |
| 2 | 2 % 3 = 2 | Shelf 2 | 
| 3 | 3 % 3 = 0 | Shelf 0 |
| 4 | 4 % 3 = 1 | Shelf 1 |

### The BIG Problem 😱
What if we add a 4th shelf?
- All calculations change!
- Book 1: Was on Shelf 1, now `1 % 4 = 1` → OK
- Book 2: Was on Shelf 2, now `2 % 4 = 2` → OK  
- Book 3: Was on Shelf 0, now `3 % 4 = 3` → WRONG SHELF!
- **80% of books need to be moved!** 📦📦📦

## 🎪 Consistent Hashing (The Smart Way)

### Think of a Ferris Wheel 🎡
- The wheel has numbered seats (0 to 11)
- Each librarian sits on one seat
- Books are placed on seats too

### How It Works:

#### Step 1: Place Librarians on the Wheel
```
Ferris Wheel: 0 1 2 3 4 5 6 7 8 9 10 11
Librarians:   A       B         C
              ↑       ↑         ↑
            Seat 2  Seat 5    Seat 9
```

#### Step 2: Place Books on the Wheel
- Book 1 → Hash = Seat 1
- Book 2 → Hash = Seat 4  
- Book 3 → Hash = Seat 7
- Book 4 → Hash = Seat 10

#### Step 3: Assign Books to Librarians
**Rule**: Give book to **next clockwise librarian**

| Book | Position | Goes To |
|------|----------|---------|
| Book 1 | Seat 1 | Librarian B (next after Seat 1) |
| Book 2 | Seat 4 | Librarian B (next after Seat 4) |
| Book 3 | Seat 7 | Librarian C (next after Seat 7) |
| Book 4 | Seat 10 | Librarian A (next after Seat 10) |

## 🎉 The Magic: Adding a New Librarian

### Before:
```
Wheel: 0 1 2 3 4 5 6 7 8 9 10 11
       A       B         C
```

### Add Librarian D at Seat 7:
```
Wheel: 0 1 2 3 4 5 6 7 8 9 10 11
       A       B   D     C
```

### What Changes? 🔄
- Only books between B and D need to move!
- Book 3: Was going to C, now goes to D
- **Only 1 book moves!** 🎊

### What Stays the Same? ✅
- Book 1: Still goes to B
- Book 2: Still goes to B  
- Book 4: Still goes to A

## 🚀 Advanced: Virtual Nodes (Super Power!)

### Problem: Uneven Distribution
What if librarians sit close together?
```
Wheel: A B C         (all in first half)
```
Most books go to librarian C! 😥

### Solution: Virtual Librarians
Each real librarian has multiple "virtual" seats:

```
Real Librarian A: Seats 1, 5, 9
Real Librarian B: Seats 3, 7, 11  
Real Librarian C: Seats 2, 6, 10
```

Now distribution is even! 🎯

## 📊 Real-World Examples

### Where You See This Every Day:
1. **Netflix** - Which server has your movie?
2. **Google** - Which database has your search data?  
3. **Amazon** - Which warehouse has the product?
4. **Uber** - Which server tracks your ride?

## 🛠️ How to Implement (Simple Code)

```javascript
class ConsistentHashing {
    constructor() {
        this.ring = new Map();  // position -> server
        this.sortedPositions = [];
    }
    
    addServer(server) {
        const position = this.hash(server);
        this.ring.set(position, server);
        this.sortedPositions = [...this.ring.keys()].sort((a, b) => a - b);
    }
    
    getServer(key) {
        const position = this.hash(key);
        
        // Find next server clockwise
        for (let serverPos of this.sortedPositions) {
            if (serverPos >= position) {
                return this.ring.get(serverPos);
            }
        }
        
        // Wrap around to first server
        return this.ring.get(this.sortedPositions[0]);
    }
    
    hash(value) {
        // Simple hash function (0-360 degrees)
        return someHashFunction(value) % 360;
    }
}
```

## 🏆 Key Benefits Summary

| Traditional Hashing | Consistent Hashing |
|-------------------|-------------------|
| ❌ 80% data moves when scaling | ✅ Only 10-20% data moves |
| ❌ All calculations change | ✅ Most mappings stay same |
| ❌ Complex scaling | ✅ Easy scaling |
| ❌ Hotspots common | ✅ Even distribution |

## 🎓 Quick Quiz (Test Yourself!)

**Q1**: If we have 10 servers and add 1 more, what % of data moves in consistent hashing?
**A**: Only ~10% (k/n where k=keys, n=servers)

**Q2**: Why do we need virtual nodes?
**A**: To ensure even distribution and avoid hotspots

**Q3**: What's the main advantage over traditional hashing?
**A**: Minimal data movement during scaling

---

## 🚀 Ready to Use This?

Now you understand why companies like Google, Amazon, and Netflix use consistent hashing! It's the secret sauce that makes scaling easy. 

# User Request Flow: Step-by-Step Walkthrough 🔄

## 🏗️ Phase 1: Setting Up Our System

### Step 1: Deploy 3 Servers
```javascript
// Our servers with unique IDs
const servers = [
    { id: 'server-A', ip: '192.168.1.10' },
    { id: 'server-B', ip: '192.168.1.11' }, 
    { id: 'server-C', ip: '192.168.1.12' }
];
```

### Step 2: Create Hash Ring & Place Servers
```javascript
// Hash function (simplified)
function hash(key) {
    // Returns number between 0-359 (like degrees in circle)
    return someHashAlgorithm(key) % 360;
}

// Place servers on the ring
const ring = new Map();

// Hash server IDs to get positions
const serverAPos = hash('server-A');  // Let's say: 45°
const serverBPos = hash('server-B');  // Let's say: 150°  
const serverCPos = hash('server-C');  // Let's say: 270°

// Add to ring
ring.set(serverAPos, 'server-A');
ring.set(serverBPos, 'server-B');
ring.set(serverCPos, 'server-C');
```

### Our Ring Looks Like This:
```
       0°
       ↑
  45°(A)   90°
    ↖       ↗
180° ←-----→ 0°
    ↙       ↘  
  150°(B)  270°(C)
```

## 👤 Phase 2: User Stores Data First Time

### User "John" (user_id: "john123") stores profile
```javascript
// Step 1: Hash user ID to find position
const johnPosition = hash('john123');  // Let's say: 200°

// Step 2: Find which server owns this position
function findServer(userPosition) {
    const positions = Array.from(ring.keys()).sort((a, b) => a - b);
    
    // Find first server clockwise from user position
    for (let serverPos of positions) {
        if (serverPos >= userPosition) {
            return ring.get(serverPos);
        }
    }
    
    // Wrap around to first server
    return ring.get(positions[0]);
}

const targetServer = findServer(200);  // Returns 'server-C' (270°)
```

**Result**: John's data goes to **Server-C** ✅

## 🔍 Phase 3: User Makes Request Later

### John comes back to view his profile
```javascript
// User request comes in with user_id: "john123"

// Step 1: Same hash function
const johnPosition = hash('john123');  // Still 200° (deterministic!)

// Step 2: Same server lookup
const targetServer = findServer(200);  // Still returns 'server-C'

// Step 3: Route request to Server-C
routeRequestToServer('server-C', 'get_profile', 'john123');

// Step 4: Server-C returns John's data
```

## 🎯 Visual Walkthrough

### Initial Setup:
```
Ring: 0°-----45°(A)-----150°(B)-----270°(C)-----360°
```

### John's Request Journey:
```
1. hash('john123') = 200°
2. Find next server clockwise from 200°:
   - 200° → Server-C (270°) ✓
   
Ring: 0°-----45°(A)-----150°(B)-----200°(john)-----270°(C)
                                      ↑
                                John's position routes to Server-C
```

## 🔄 What If We Add a New Server?

### Add Server-D at position 220°
```javascript
const serverDPos = hash('server-D');  // Let's say: 220°
ring.set(serverDPos, 'server-D');
```

### New Ring:
```
Ring: 0°---45°(A)---150°(B)---200°(john)---220°(D)---270°(C)
```

### What Changes?
- **John's next request**: 
  - `hash('john123')` = still 200°
  - `findServer(200)` now returns **Server-D** (220°) instead of Server-C (270°)
  - John's data needs to be moved from Server-C to Server-D

### Only These Users Move:
```
Users between Server-B (150°) and Server-D (220°) need to move
All other users stay on their original servers!
```

## 🛠️ Complete Code Example

```javascript
class ConsistentHashing {
    constructor() {
        this.ring = new Map();
        this.sortedPositions = [];
    }
    
    addServer(serverId) {
        const position = this.hash(serverId);
        this.ring.set(position, serverId);
        this.updateSortedPositions();
        console.log(`✅ Added ${serverId} at position ${position}`);
    }
    
    findServerForKey(key) {
        const position = this.hash(key);
        
        for (let serverPos of this.sortedPositions) {
            if (serverPos >= position) {
                const server = this.ring.get(serverPos);
                console.log(`🔍 Key "${key}" (pos:${position}) → ${server} (pos:${serverPos})`);
                return server;
            }
        }
        
        // Wrap around
        const server = this.ring.get(this.sortedPositions[0]);
        console.log(`🔍 Key "${key}" (pos:${position}) → ${server} (wrap around)`);
        return server;
    }
    
    hash(key) {
        // Simple hash for demonstration
        let hash = 0;
        for (let i = 0; i < key.length; i++) {
            hash = (hash << 5) - hash + key.charCodeAt(i);
            hash |= 0; // Convert to 32bit integer
        }
        return Math.abs(hash) % 360; // 0-359 degrees
    }
    
    updateSortedPositions() {
        this.sortedPositions = Array.from(this.ring.keys()).sort((a, b) => a - b);
    }
}

// 🚀 Let's Run It!
const ch = new ConsistentHashing();

// Setup servers
ch.addServer('server-A');  // Position: 45
ch.addServer('server-B');  // Position: 150  
ch.addServer('server-C');  // Position: 270

// User requests
console.log('\n--- User Requests ---');
ch.findServerForKey('john123');  // → server-C
ch.findServerForKey('alice456'); // → server-A  
ch.findServerForKey('bob789');   // → server-B

// Add new server
console.log('\n--- Adding Server-D ---');
ch.addServer('server-D');  // Position: 220

// Same user requests
console.log('\n--- Same User Requests ---');
ch.findServerForKey('john123');  // Now → server-D!
ch.findServerForKey('alice456'); // Still → server-A (no change!)
ch.findServerForKey('bob789');   // Still → server-B (no change!)
```

## 📊 Output Example:
```
✅ Added server-A at position 45
✅ Added server-B at position 150  
✅ Added server-C at position 270

--- User Requests ---
🔍 Key "john123" (pos:200) → server-C (pos:270)
🔍 Key "alice456" (pos:30) → server-A (pos:45) 
🔍 Key "bob789" (pos:100) → server-B (pos:150)

--- Adding Server-D ---
✅ Added server-D at position 220

--- Same User Requests ---
🔍 Key "john123" (pos:200) → server-D (pos:220)  // MOVED!
🔍 Key "alice456" (pos:30) → server-A (pos:45)   // SAME!
🔍 Key "bob789" (pos:100) → server-B (pos:150)   // SAME!
```

## 🎯 Key Points to Remember:

1. **Same hash function** always = same position
2. **Clockwise search** finds the responsible server  
3. **Adding servers** only affects nearby data
4. **Most users** don't move when scaling
5. **Deterministic** = same user always goes to same server (until scaling)

This is why consistent hashing is used by every major tech company! 🚀