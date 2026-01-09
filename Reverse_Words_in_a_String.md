## Reverse Words in a String

### Problem Statement

Given a string `s` that may contain **leading spaces, trailing spaces, or multiple spaces between words**, reverse the **order of words** and return a clean string with **single spaces only**.

A **word** is a sequence of non-space characters.

### Key Idea

We solve this problem in **two steps**:

1. **Extract all words** from the string (ignoring extra spaces)
2. **Rebuild the string** by adding words in **reverse order**

### Approach Explanation

We scan the string character by character and store each word in a list.

#### Step 1: Extract Words

* Use a pointer `i` to traverse the string
* Skip all spaces
* When a non-space character is found:

  * Mark the start of the word
  * Continue until we hit a space again
  * Extract the word using `substr`
  * Store it in a vector `words`

This ensures:

* No empty words
* Extra spaces are ignored

#### Step 2: Reverse Words

* Traverse the `words` vector from **last to first**
* Append each word to the result string
* Add a space **only between words**, not at the end

### Algorithm

1. Initialize index `i = 0`
2. While `i < n`:

   * Skip spaces
   * Capture characters until next space → one word
   * Store the word
3. Iterate over stored words from back to front
4. Join them with a single space
5. Return the final string

### C++ Code

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        vector<string> words;

        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ') i++;

            if (i < n) {
                int start = i;
                // Read the word
                while (i < n && s[i] != ' ') i++;
                words.push_back(s.substr(start, i - start));
            }
        }

        string result = "";
        // Build answer in reverse order
        for (int j = words.size() - 1; j >= 0; --j) {
            result += words[j];
            if (j > 0) result += " ";
        }

        return result;
    }
};
```

### Example

**Input**

```
s = "  hello   world  "
```

**Words extracted**

```
["hello", "world"]
```

**Reversed result**

```
"world hello"
```

### Complexity Analysis

* **Time Complexity:** `O(n)`
  (Each character is processed once)
* **Space Complexity:** `O(n)`
  (Extra space for storing words)
