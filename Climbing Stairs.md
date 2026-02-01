## Approach

The function uses a dynamic programming approach to solve the problem efficiently what we have do is :

- Initialize a and b where a represents the number of ways to reach the first stair (n = 1), which is 1 (a = 1), and b represents the number of ways to reach the second stair (n = 2), which is 2 (b = 2).
- Use a loop to iterate from 3 up to n. In each iteration:
- Calculate c as the sum of a and b, which represents the number of ways to reach the current stair (i).
- Update a to be the previous value of b (which now represents the number of ways to reach the stair before i).
- Update b to be c, which now represents the number of ways to reach stair.

After the loop finishes, b will contain the number of distinct ways to reach the top of n stairs, which is returned as the result.

## Complexity
- Time Complexity: O(n)
- Space Complexity: O(1)

## Code
```
class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
