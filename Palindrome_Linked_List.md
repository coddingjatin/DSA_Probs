## Palindrome Linked List

### Problem Statement

Given the `head` of a **singly linked list**, check whether the linked list is a **palindrome** or not.

A linked list is called a palindrome if it reads the same **forward and backward**.

### Key Idea

Hum linked list ko **array me convert nahi karenge** (extra space avoid karne ke liye).

Instead, hum:

1. **Middle node** find karenge (Slow & Fast pointer)
2. **Second half of linked list reverse** karenge
3. **First half aur reversed second half compare** karenge

### Approach (Step-by-Step)

#### Step 1: Find the Middle of the Linked List

* `slow` pointer → 1 step
* `fast` pointer → 2 steps

Jab `fast` end par pahunch jaata hai, `slow` middle par hota hai.

#### Step 2: Reverse the Second Half

* Middle ke baad wali linked list ko **reverse** kar dete hain
* Isse last se comparison easy ho jaata hai

#### Step 3: Compare Both Halves

* `fast` ko head se start karte hain
* `slow` ko reversed list ke start se
* Agar kisi bhi point par values mismatch → **not palindrome**


### Algorithm

1. Initialize `slow` and `fast` pointers at `head`
2. Move:

   * `slow = slow.next`
   * `fast = fast.next.next`
3. Split the list into two halves
4. Reverse the second half
5. Compare nodes from:

   * First half
   * Reversed second half
6. If all values match → return `true`
7. Else → return `false`


### Java Code

```java
class Solution {
    public boolean isPalindrome(ListNode head) {

        // Step 1: Find middle using slow & fast pointers
        ListNode slow = head, fast = head, prev, temp;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Step 2: Reverse second half
        prev = slow;
        slow = slow.next;
        prev.next = null;

        while (slow != null) {
            temp = slow.next;
            slow.next = prev;
            prev = slow;
            slow = temp;
        }

        // Step 3: Compare both halves
        fast = head;
        slow = prev;

        while (slow != null) {
            if (fast.val != slow.val)
                return false;
            fast = fast.next;
            slow = slow.next;
        }

        return true;
    }
}
```

### Example

**Input**

```
1 → 2 → 2 → 1
```

**Process**

* Middle found at `2`
* Second half reversed → `1 → 2`
* Compare both halves → all values match ✅

**Output**

```
true
```

---

### Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

