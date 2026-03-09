#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int X, Y;
        cin >> X >> Y;

        if (Y > X) cout << "YES";
        else cout << "NO";

        cout << endl;
    }

    return 0;
}
