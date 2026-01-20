#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigit(int n) {
        if(n == 0) return 1;
        int cnt = 0;
        while(n > 0) {
            cnt = cnt + 1; 
            n = n / 10;
        }
        
        return cnt;
    }
};

int main()
{
    int n = 6678;
    Solution sol; 
    int ans = sol.countDigit(n);
    cout << "The count of digits in the given number is: " << ans;
    return 0;
}
