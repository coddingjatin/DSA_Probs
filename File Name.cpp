#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0, ans = 0;

    for (char c : s) {
        if (c == 'x') {
            cnt++;
            if (cnt >= 3) ans++;
        } else {
            cnt = 0;
        }
    }

    cout << ans;
}
