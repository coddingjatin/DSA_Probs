#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        if (n != 5) {
            cout << "NO\n";
            continue;
        }
        
        sort(s.begin(), s.end());
        if (s == "Timru")
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
