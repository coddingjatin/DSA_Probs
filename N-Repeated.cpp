//N-Repeated Element in Size 2N Array

/*Problem Explanation: 

You are given a list of integers nums that has the following characteristics:
The length of nums is 2 * n.
The list contains exactly n + 1 unique elements.
Exactly one element is repeated n times.
Your task is to find that element that is repeated n times.

For example:

In the list [1, 2, 3, 3], 3 is repeated twice, so the answer is 3.
In the list [2, 1, 2, 5, 3, 2], 2 is repeated three times, so the answer is 2.
In the list [5, 1, 5, 2, 5, 3, 5, 4], 5 is repeated four times, so the answer is 5.*/

//Code
#include <unordered_map>
#include <vector>

class Solution {
public:
    int repeatedNTimes(std::vector<int>& A) {
        std::unordered_map<int, int> count;
        for (int num : A) {
            count[num]++;
            if (count[num] == A.size() / 2) {
                return num;
            }
        }
        return -1;
    }
};


/* How This Code Works:

1. unordered_map: This is used to store the count of each element. The key is the element, and the value is how many times it appears in the list.
2. Loop: We loop through each element of the array A. For each number, we increase its count in the count map.
3. Condition: We check if the count of the number has reached n (which is A.size() / 2). Since n is half the length of the array, the repeated element will appear exactly n times.
4. Return: Once we find an element that is repeated n times, we return it immediately.

Example Walkthrough:
Example 1: nums = [1, 2, 3, 3]

Initially, count is empty: {}.

Iterating through the array:
First element is 1: count[1] = 1, continue.
Next element is 2: count[2] = 1, continue.
Next element is 3: count[3] = 1, continue.
Next element is 3 again: count[3] = 2, now count[3] is equal to 2 (which is n), so return 3.

Example 2: nums = [2, 1, 2, 5, 3, 2]

Initially, count is empty: {}.
Iterating through the array:
2 appears first: count[2] = 1.
1 appears count[1] = 1.
2 appears again: count[2] = 2.
5 appears: count[5] = 1.
3 appears: count[3] = 1.
2 appears again: count[2] = 3, which is n = 3, so return 2.

Time Complexity: O(n)
Space Complexity O(n)
*/
