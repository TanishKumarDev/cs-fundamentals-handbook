# Consistent Hashing - System Design Notes

## 🎯 What is Consistent Hashing?
- **Distributed hashing technique** used in load balancing
- **Goal**: Minimize rehashing when number of nodes changes
- Uses **virtual ring structure** (hash ring) to represent clients and servers

## 🔄 Traditional Hashing Problems

### Issues with Simple Hashing:
1. **Uneven Data Distribution**
   - Some servers get more data, others get very little
   - Poor load balancing

2. **Scalability Problems**
   - Adding/removing servers requires redistributing **all data**
   - Inefficient and causes delays

3. **Inflexibility**
   - Struggles to adapt to changing number of servers
   - System becomes unstable during scaling

4. **Node Failure Handling**
   - Failed server data becomes inaccessible
   - No graceful failure recovery

5. **High Rehashing Overhead**
   - Most keys need remapping during scaling
   - High computational cost

## 🎪 Consistent Hashing Solution

### Core Concept:
- **Virtual ring** with infinite points
- Servers placed at random locations using hash function
- Requests placed on same ring using same hash function
- **Clockwise traversal** to find serving server

### How It Works:
```
Hash Ring: 0°---ServerA---ServerB---ServerC---360°
Request → Hashed to position → Find next server clockwise
```

## 🛠️ Implementation Phases

### Phase 1: Hash Function Selection
- Choose **deterministic** hash function (MD5, SHA-1, SHA-256)
- Produces unique value for each key
- Uniform distribution across ring

### Phase 2: Node Assignment
- Nodes arranged in circle
- Keys assigned to **nearest clockwise node**

### Phase 3: Key Replication
- Copy keys across multiple nodes
- Ensures data availability during failures

### Phase 4: Node Addition/Removal
- Only **small number of keys** remapped
- Minimal impact on system

### Phase 5: Load Balancing
- Monitor keys per node
- Redistribute if imbalance detected

### Phase 6: Failure Recovery
- Remap failed node keys to other nodes
- Maintain data availability

### Phase 7: Load Balancing
- Periodically chcek the load on each node by monitoring the number of keys it owns
- In the case of imbalance, conider redistributing some keys to achieve a more even distribution

## 💻 Code Implementation

```cpp
class ConsistentHashRing {
private:
    map<int, string> ring;
    set<int> sorted_keys;
    int replicas;

    int get_hash(const string& value) {
        hash<string> hash_function;
        return hash_function(value);
    }

public:
    ConsistentHashRing(int replicas = 3) : replicas(replicas) {}

    // Add node with virtual replicas
    void add_node(const string& node) {
        for (int i = 0; i < replicas; ++i) {
            int replica_key = get_hash(node + "_" + to_string(i));
            ring[replica_key] = node;
            sorted_keys.insert(replica_key);
        }
    }

    // Remove node and its replicas
    void remove_node(const string& node) {
        for (int i = 0; i < replicas; ++i) {
            int replica_key = get_hash(node + "_" + to_string(i));
            ring.erase(replica_key);
            sorted_keys.erase(replica_key);
        }
    }

    // Find node for a key
    string get_node(const string& key) {
        if (ring.empty()) return "";
        
        int hash_value = get_hash(key);
        auto it = sorted_keys.lower_bound(hash_value);
        
        if (it == sorted_keys.end()) {
            it = sorted_keys.begin();  // Wrap around
        }
        
        return ring[*it];
    }
};
```

### Usage Example:
```cpp
ConsistentHashRing hash_ring;

// Add nodes
hash_ring.add_node("Node_A");
hash_ring.add_node("Node_B");
hash_ring.add_node("Node_C");

// Find node for key
string key = "first_key";
string node = hash_ring.get_node(key);
// Output: "The key 'first_key' is mapped to node: Node_C"
```

## ✅ Advantages

1. **Load Balancing**
   - Even distribution of workload
   - Maintains efficiency as data grows

2. **Scalability**
   - Adapts to node count changes
   - Minimal performance impact

3. **Minimal Remapping**
   - Only small portion of keys moved during scaling
   - System remains stable

4. **Failure Tolerance**
   - Data remains available during node failures
   - Automatic key remapping

5. **Simplified Operations**
   - Easy node addition/removal
   - Simplified large system management

## ❌ Disadvantages

1. **Hash Function Complexity**
   - Requires careful hash function selection
   - Complexity affects system efficiency

2. **Performance Cost**
   - Computational overhead for key mapping
   - Replication and remapping costs

3. **Limited Flexibility**
   - Rigid boundaries may limit adaptation
   - Constrained by ring structure

4. **High Resource Usage**
   - Can lead to high resource utilization
   - Affects overall performance

5. **Management Complexity**
   - Requires specialized skills
   - Complex to maintain

## 🎯 Key Takeaways

- **Solves scaling problems** of traditional hashing
- **Minimal data movement** during node changes
- **Virtual nodes** help with even distribution
- **Widely used** in distributed systems
- **Essential for scalable system design**

## 📊 Real-World Applications
- **Distributed databases** (Cassandra, DynamoDB)
- **Content delivery networks** (CDNs)
- **Load balancers**
- **Caching systems**

---

*Consistent hashing is fundamental for building scalable, fault-tolerant distributed systems that can handle dynamic node changes efficiently.*