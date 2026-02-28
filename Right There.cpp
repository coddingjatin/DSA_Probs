#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, X;
        cin >> N >> X;

        if (N <= X)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
