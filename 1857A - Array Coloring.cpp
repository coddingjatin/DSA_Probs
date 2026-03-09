#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int x, sum = 0, odd = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            sum += x;
            if (x % 2) odd++;
        }
        if (sum % 2 == 1) cout << "NO\n";
        else {
            if (odd == 0) cout << "NO\n";
            else cout << "YES\n";
        }
    }

    return 0;
}
