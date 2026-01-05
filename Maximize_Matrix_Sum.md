## **Max Matrix Sum**

We are given a matrix that may contain **positive and negative numbers**.
We can **flip the sign of any element any number of times**.
Our goal is to get the **maximum possible sum of all elements**.

### **Main Idea**

1. **Absolute values always help**
   No matter if a number is negative or positive, its **absolute value** increases the sum.

2. **Count negative numbers**

   * If the number of negative elements is **even**, we can flip all negatives to positives.
   * If the number of negative elements is **odd**, one element must stay negative.

3. **Minimize the loss**

   * If one number must remain negative, choose the number with the **smallest absolute value**.
   * This gives the smallest reduction in the total sum.

## CODE
```cpp
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        long long mi = LLONG_MAX;
        int negCount = 0;

        for (auto& row : matrix) {
            for (int v : row) {
                sum += abs(v);
                mi = min(mi, (long long)abs(v));
                if (v < 0) negCount++;
            }
        }

        return (negCount % 2 == 0) ? sum : sum - 2 * mi;
    }
};
```
### **What the Code Does**

* Adds the **absolute value** of every element to the total sum.
* Tracks the **smallest absolute value** in the matrix.
* Counts how many elements are negative.
* If negative count is even → return the total sum.
* If negative count is odd → subtract `2 × smallest absolute value` from the sum.


### **Why subtract `2 × min`?**

When a number stays negative instead of positive:

* Positive contribution would be `+min`
* Actual contribution is `-min`
* Difference = `2 × min`

### **Example**

**Matrix:**

```
[[-1, 2],
 [ 3, 4]]
```

* Absolute sum = `1 + 2 + 3 + 4 = 10`
* Negative count = 1 (odd)
* Smallest absolute value = 1
* Maximum sum = `10 - 2 × 1 = 8`

### **Final Result**

This approach guarantees the **maximum possible matrix sum** with:

* **Time Complexity:** `O(n × m)`
* **Space Complexity:** `O(1)`
