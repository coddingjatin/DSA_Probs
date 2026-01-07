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
                j++;
                i++;
                if (j == n) {
                    return true;
                }
            } else {
                if (j != 0) {
                    i=i-j+1;
                    j = 0;
                } else {
                    i++;
                }
            }
        }

        return false;
    }
};
