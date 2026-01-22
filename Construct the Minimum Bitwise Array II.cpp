class Solution {
public:
  vector<int> minBitwiseArray(vector<int>& A) {
    vector<int> ans;
    for (int x : A) { 
        if (x % 2 == 0) {
            ans.push_back(-1);
            continue;
        }
        int y = x + 1;
        int bit = y & (-y);
        ans.push_back(x - bit / 2);
    }
    return ans;
}
};
 
