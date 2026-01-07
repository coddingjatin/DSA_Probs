## Rotate String

We are given two strings **s** and **goal**.
We can rotate string **s** any number of times.
Our task is to check **whether `s` can become `goal` after rotations**.

A rotation means:

* Take characters from the front of the string
* Move them to the end

## Main Idea

### Length must be equal

If the lengths of `s` and `goal` are different, rotation is impossible.

### Key Observation

If `goal` is a rotation of `s`, then:

```
s will appear as a substring in (goal + goal)
```

Example:

```
goal = "abcde"
goal + goal = "abcdeabcde"
s = "cdeab"   ← appears inside
```

So instead of rotating manually, we just **search for `s` inside `goal + goal`**.

## Algorithm (Manual String Matching)

We use **two pointers**:

* `i` → iterates over `goal + goal`
* `j` → iterates over `s`

Steps:

1. Compare characters at `concatenated[i]` and `s[j]`
2. If they match → move both pointers forward
3. If mismatch:

   * If `j > 0`, reset `j` and shift `i` properly
   * Otherwise, just move `i` forward
4. If `j` reaches the length of `s`, it means the full string matched → return `true`

If the loop ends without full match → return `false`

## Code

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        string concatenated = goal + goal;
        int i = 0;
        int j = 0;
        int n = s.size();
        int m = concatenated.size();

        while (i < m) {
            if (concatenated[i] == s[j]) {
                i++;
                j++;
                if (j == n) {
                    return true;
                }
            } else {
                if (j != 0) {
                    i = i - j + 1;
                    j = 0;
                } else {
                    i++;
                }
            }
        }

        return false;
    }
};
```

## What the Code Does

* First checks if both strings have the same length
* Creates `goal + goal` to simulate all rotations
* Uses two pointers to compare characters
* Resets matching when mismatch occurs
* Returns `true` as soon as full string `s` is matched

## Example

### Input

```
s = "cdeab"
goal = "abcde"
```

### Process

```
goal + goal = "abcdeabcde"
```

`"cdeab"` exists inside this string

### Output

```
true
```

## Final Result

* **Time Complexity:** `O(n²)`
* **Space Complexity:** `O(n)` 
