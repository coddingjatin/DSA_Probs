## Maximum Dot Product of Two Subsequences

### Problem Statement

Given two integer arrays `nums1` and `nums2`, return the **maximum dot product** between **non-empty subsequences** of the two arrays.

A dot product of two arrays `[a1, a2, ..., ak]` and `[b1, b2, ..., bk]` is:
`a1*b1 + a2*b2 + ... + ak*bk`

### Key Idea

We use **Dynamic Programming with Recursion (Top-Down DP)**.

At any index `(i, j)`, we have three choices:

1. **Take** the current elements `nums1[i]` and `nums2[j]`
2. **Skip** element from `nums1`
3. **Skip** element from `nums2`

Since subsequence must be **non-empty**, we handle negative values carefully.

### State Definition

Let
`dp[i][j]` = maximum dot product using elements from
`nums1[i ... n-1]` and `nums2[j ... m-1]`

### Recurrence Relation

At position `(i, j)`:

* **Take both elements**

```
take = nums1[i] * nums2[j] + max(0, dp[i+1][j+1])
```

* **Skip nums1[i]**

```
skip1 = dp[i+1][j]
```

* **Skip nums2[j]**

```
skip2 = dp[i][j+1]
```

Final answer:

```
dp[i][j] = max(take, skip1, skip2)
```

### Base Case

If we reach the end of either array:

```
if (i == n || j == m)
    return -∞
```

(Used `-1e9` to ensure we don't choose empty subsequence.)

### Algorithm

1. Use recursion with memoization (`dp` array)
2. Start from indices `(0, 0)`
3. At each step:

   * Try taking both elements
   * Try skipping one element
4. Store and reuse results using `dp`
5. Return `dp[0][0]`

### C++ Code

```cpp
class Solution {
public:
    int dp[501][501];
    vector<int> a, b;
    int n, m;

    int solve(int i, int j) {
        if (i == n || j == m) return -1e9;

        if (dp[i][j] != -1) return dp[i][j];

        int take = a[i] * b[j] + max(0, solve(i+1, j+1));
        int skip1 = solve(i+1, j);
        int skip2 = solve(i, j+1);

        return dp[i][j] = max({take, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        n = a.size();
        m = b.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};
```


### Example

**Input**

```
nums1 = [2,1,-2,5]
nums2 = [3,0,-6]
```

**Best subsequences**

```
[2,5] and [3,-6]
Dot Product = 2*3 + 5*(-6) = 6 - 30 = -24
```

### Complexity Analysis

* **Time Complexity:** `O(n × m)`
* **Space Complexity:** `O(n × m)` (DP table)

