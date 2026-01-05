## **Max Matrix Sum — Explanation**

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



### **What the Code Does**

* Adds the **absolute value** of every element to the total sum.
* Tracks the **smallest absolute value** in the matrix.
* Counts how many elements are negative.
* If negative count is even → return the total sum.
* If negative count is odd → subtract `2 × smallest absolute value` from the sum.

---

### **Why subtract `2 × min`?**

When a number stays negative instead of positive:

* Positive contribution would be `+min`
* Actual contribution is `-min`
* Difference = `2 × min`

---

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

---

### **Final Result**

This approach guarantees the **maximum possible matrix sum** with:

* **Time Complexity:** `O(n × m)`
* **Space Complexity:** `O(1)`

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

---

## **How This Code Works:**

### **Step 1: Initialize Variables**

* `sum` → sab elements ke absolute values ka total
* `mi` → smallest absolute value (minimum loss ke liye)
* `negCount` → negative numbers ki count

---

### **Step 2: Traverse Matrix**

Har element `v` ke liye:

* `abs(v)` ko `sum` me add karo
* `mi` update karo agar current absolute value chhoti ho
* agar `v < 0` → `negCount++`

---

### **Step 3: Final Decision**

* **Even negative count** → sab positive ho sakte hain → return `sum`
* **Odd negative count** →
  ek number negative rehna padega →
  maximum sum = `sum - 2 * mi`

(kyunki ek number ko negative rakhne ka loss = `2 × smallest absolute value`)

---

## **Example Walkthrough**

### **Example 1**

```
matrix = [[1, -2],
          [-3, 4]]
```

* Absolute sum = 1 + 2 + 3 + 4 = **10**
* Negative count = 2 (even)
* Answer = **10**

---

### **Example 2**

```
matrix = [[-1, 2],
          [3, 4]]
```

* Absolute sum = 1 + 2 + 3 + 4 = **10**
* Negative count = 1 (odd)
* Smallest absolute value = 1
* Answer = `10 - 2*1 = 8`

---

## **Time and Space Complexity**

* **Time Complexity:** `O(n × m)`
  (matrix ke har element ko ek baar traverse karte hain)

* **Space Complexity:** `O(1)`
  (sirf few variables use ho rahe hain)

---

Agar chaho to main isko:

* LeetCode style explanation
* Ya sirf short interview notes
* Ya dry-run diagram ke saath

bhi bana deta hoon 😊
