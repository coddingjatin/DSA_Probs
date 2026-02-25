#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if ((a + 2 * b) % 2 != 0) {
            cout << "No\n";
        } else {
            if (b % 2 == 1 && a < 2)
                cout << "No\n";
            else
                cout << "Yes\n";
        }
    }

    return 0;
}
