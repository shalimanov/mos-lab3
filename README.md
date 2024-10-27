# Lab 3, Cache

## Research Objective
Investigate impact of different memory access modes and synchronization mechanisms on cache&memory efficiency.

---

### 1. Synchronization in Shared Memory Access

- **Atomic**: Safe, but slower.
- **Volatile**: Updated, but unsafe.
- **No synchronization**: Fastest, but incorrect results.

---

### 2. Sequential vs Random Memory Access

- **Sequential Access**: Faster due to prefetching.
- **Random Access**: Slower; causes cache misses.

---

### 3. Cache Misses with Large Data Arrays

- **Sequential Access**: Handles cache limits efficiently.
- **Random Access**: Frequent cache misses, slower.

---

### 4. Cache Latency

- **Small Arrays**: Low latency, fast access.
- **Increasing Array Sizes**: High latency, frequent misses.

---