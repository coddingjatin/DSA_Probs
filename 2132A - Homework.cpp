#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string a, b, c;
        cin >> n;
        cin >> a;
        cin >> m;
        cin >> b;
        cin >> c;

        deque<char> d;
        for (char x : a) d.push_back(x);

        for (int i = 0; i < m; i++) {
            if (c[i] == 'V') d.push_front(b[i]);
            else d.push_back(b[i]);
        }

        for (char x : d) cout << x;
        cout << '\n';
    }
}
