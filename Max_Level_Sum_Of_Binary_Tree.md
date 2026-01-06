## Max Level Sum of Binary Tree

### Problem Statement

Given the **root of a binary tree**, find the **level number** (1-indexed) which has the **maximum sum of node values**.


### Key Idea

We traverse the tree **level by level** (using **BFS / Level Order Traversal**).

For each level:

* Calculate the **sum of all node values** at that level
* Compare it with the **maximum sum so far**
* Update the answer if current level sum is greater


### Algorithm

1. Use a **queue** for level order traversal.
2. Start with **level = 1**.
3. For each level:

   * Find how many nodes are present (`size = queue.size()`)
   * Process exactly those many nodes
   * Add their values to `sum`
   * Push their left and right children into the queue
4. If `sum > maxSum`, update:

   * `maxSum = sum`
   * `ans = level`
5. Move to the next level.
6. Return `ans`.


### C++ Code

```cpp
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1, ans = 1;
        int maxSum = root->val;

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (sum > maxSum) {
                maxSum = sum;
                ans = level;
            }

            level++;
        }

        return ans;
    }
};
```

### Example

**Tree:**

```
        1
       / \
      7   0
     / \
    7  -8
```

**Level-wise sum:**

* Level 1 → `1`
* Level 2 → `7 + 0 = 7`
* Level 3 → `7 + (-8) = -1`

**Maximum sum is at Level 2**

### Complexity Analysis

* **Time Complexity:** `O(n)` (each node visited once)
* **Space Complexity:** `O(n)` (queue for BFS)

