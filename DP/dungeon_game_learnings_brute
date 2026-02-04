## Summary Notes: Dungeon Game Bug Analysis

---

### The Problem

Given a dungeon grid, find minimum starting health to reach the end (staying alive throughout).

---

### Your Bug: Processing the Wrong Cell

**Example: `dungeon = [[-3, 5]]`** (1 row, 2 columns)

Starting health `h = 3`

---

### What Your Code Did (WRONG ❌)

```cpp
// At cell (0,0) with h=3
if (i == end && j == end)  // Not at destination, skip
if (h <= 0) return false;  // h=3, okay, continue

// Recurse to (0,1) passing h + dungeon[0][0] = 3 + (-3) = 0
ispossible(0, 1, 0, dungeon)

// Now at cell (0,1) with h=0
if (i == end && j == end)  // YES! At destination
    if (h + dungeon[0][1] > 0)  // 0 + 5 = 5 > 0? YES!
        return true  // ← WRONG! Knight was already dead!
```

**Your code said h=3 works, but the knight DIED at cell (0,0)!**

Timeline:
```
Cell (0,0): Enter with h=3 → Apply -3 → h=0 → DEAD! 💀
```

---

### What Should Happen (CORRECT ✓)

```cpp
bool ispossible(int i, int j, int h, dungeon) {
    if (out of bounds) return false;
    
    h = h + dungeon[i][j];  // Process CURRENT cell FIRST
    
    if (h <= 0) return false;  // Check death IMMEDIATELY
    
    if (at destination) return true;
    
    return recurse(down) || recurse(right);
}
```

With h=3:
```
Cell (0,0): h = 3 + (-3) = 0 → Dead! Return false ✓
```

With h=4:
```
Cell (0,0): h = 4 + (-3) = 1 → Alive!
Cell (0,1): h = 1 + 5 = 6 → Alive! At destination! Return true ✓
```

---

### Golden Rules to Remember

| Rule | Description |
|------|-------------|
| **1** | Process the cell you're ON, not the one you came from |
| **2** | Apply cell effect FIRST, then check death |
| **3** | Order: Bounds → Apply effect → Death check → Destination check → Recurse |

---

### Memory Trick

```
"Enter → Experience → Survive? → Continue"

You can't walk through a room without feeling its effect first!
```

---

### Quick Template

```cpp
bool solve(int i, int j, int h, grid) {
    if (i >= n || j >= m) return false;     // 1. Bounds
    
    h = h + grid[i][j];                      // 2. Experience current room
    
    if (h <= 0) return false;                // 3. Did I survive?
    
    if (i == n-1 && j == m-1) return true;   // 4. Destination?
    
    return solve(i+1,j,h) || solve(i,j+1,h); // 5. Move on
}
```
