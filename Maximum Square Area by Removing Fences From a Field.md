## Maximum Square Area by Removing Fences From a Field

### Problem Statement

You are given a rectangle of size **`m x n`**.

You are also given:

* `h` → horizontal fence positions
* `v` → vertical fence positions

Fences divide the rectangle into smaller rectangles.

Your task is to find the **maximum possible area of a square** that can be formed using these fences.

If **no square is possible**, return `-1`.

Return the answer **modulo (10⁹ + 7)**.

### Key Idea

A square is possible **only if**:

* Horizontal distance == Vertical distance

So the idea is:

1. Find **all possible distances** between every pair of horizontal fences
2. Find **all possible distances** between every pair of vertical fences
3. Find the **largest common distance**
4. Square area = `distance × distance`

### Important Observations

* We must include the **boundary fences**:

  * Horizontal → `1` and `m`
  * Vertical → `1` and `n`
* Distance between any two fences can form a side of a square
* Use **unordered_set** to store all possible distances efficiently

### Algorithm

1. Add boundary fences:

   * `h.push_back(1), h.push_back(m)`
   * `v.push_back(1), v.push_back(n)`
2. Sort both arrays
3. Generate **all possible distances**:

   * For horizontal → store in set `s1`
   * For vertical → store in set `s2`
4. For every distance in `s1`:

   * Check if same distance exists in `s2`
   * If yes → calculate `distance²`
   * Keep track of maximum area
5. If no square found → return `-1`
6. Else return `maxArea % mod`


### C++ Code

```cpp
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        int mod = 1e9 + 7;
        unordered_set<int> s1, s2;

        // Add boundary fences
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        // All possible horizontal distances
        for (int i = 0; i < h.size(); i++) {
            for (int j = i + 1; j < h.size(); j++) {
                s1.insert(h[j] - h[i]);
            }
        }

        // All possible vertical distances
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                s2.insert(v[j] - v[i]);
            }
        }

        long long ans = 0;

        // Find maximum common distance
        for (auto d : s1) {
            if (s2.find(d) != s2.end()) {
                long long area = 1LL * d * d;
                ans = max(ans, area);
            }
        }

        if (ans == 0) return -1;

        return ans % mod;
    }
};
```

### Example

**Input:**

```
m = 5, n = 4
h = [2, 4]
v = [2]
```

**Horizontal fences:** `1, 2, 4, 5`
**Possible distances:** `1, 2, 3, 4`

**Vertical fences:** `1, 2, 4`
**Possible distances:** `1, 2, 3`

**Common distances:** `1, 2, 3`
**Maximum = 3**

**Answer:** `3 × 3 = 9`
