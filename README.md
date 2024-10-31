# Lab 3, Cache

## Research Objective
Investigate impact of different memory access modes and synchronization mechanisms on cache&memory efficiency.

---

### 1. Synchronization in Shared Memory Access

- **Atomic**: Guarantees data correctness but adds latency due to synchronization overhead.
- **Volatile**: Ensures visibility of recent data but doesn't protect against race conditions.
- **No synchronization**: Fastest but unsafe, causing unpredictable results due to race conditions.

---

### 2. Sequential vs Random Memory Access

- **Sequential access**: Utilizes cache efficiently, improving speed by minimizing cache misses.
- **Random access**: Disrupts caching, increasing cache misses and reducing performance.

---

### 3. Cache Misses with Large Data Arrays

- **Sequential Access**: Prefetching reduces cache misses, preserving speed despite large data sizes.
- **Random Access**: High cache miss rate causes frequent slow memory accesses and reduced performance.

---

### 4. Cache Latency

- **Small arrays**: Minimal latency since data fits in cache, allowing fast access.
- **Increasing array sizes**: Rising latency as data exceeds cache size, increasing main memory accesses.

---

### Summary
