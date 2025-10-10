# Network and Logical Topologies
A **network topology** describes the physical or logical arrangement of devices in a network, defining how nodes (devices) are connected and how data flows. **Physical topology** refers to the actual layout of cables, devices, and connections (e.g., wiring and hardware placement). **Logical topology** describes the data flow path, regardless of physical setup (e.g., how packets travel based on protocols).

Key types of topologies:

- **Physical Topologies**:
    - **Bus**: All devices share a single cable (backbone). Simple but outdated.
    - **Star**: Devices connect to a central hub/switch. Common in modern LANs.
    - **Ring**: Each device connects to the next, forming a loop. Used in older networks like Token Ring.
    - **Mesh**: Devices are interconnected (fully or partially). High redundancy, used in WANs.
    - **Tree**: Hierarchical star networks, like enterprise LANs.
    - **Point-to-Point**: Direct link between two devices (e.g., router to router).
- **Logical Topologies**:
    - **Bus**: Data appears to flow as if all devices are on a single cable (e.g., early Ethernet).
    - **Ring**: Data travels in a logical loop (e.g., Token Ring protocol).
    - **Point-to-Point**: Data flows directly between two nodes (e.g., PPP links).
    - **Star**: Data flows through a central logical point, even if physically meshed.

Analogy: Physical topology is the road map of a city; logical topology is the traffic flow pattern, which may differ based on rules (protocols).

### Important Aspects

- **Performance**: Star topology (physical/logical) is fast due to dedicated paths but fails if the central hub dies. Mesh offers redundancy but is complex and costly. Why? More links increase reliability but complicate setup.
- **Scalability**: Tree scales well for enterprises (e.g., campus networks); bus struggles with many devices due to collisions. Why? Bandwidth sharing limits bus efficiency.
- **Cost**: Bus is cheapest (single cable); mesh is expensive (many cables). Logical topologies save cost by simulating complex setups (e.g., VLANs create logical stars on physical trees).
- **Why It Matters**: Topology impacts reliability, speed, and cost. Example: A poorly chosen topology (bus for a busy office) causes bottlenecks. Modern trend: Hybrid topologies (e.g., star-tree) and virtual logical topologies in SDN.