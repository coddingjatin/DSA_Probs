#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int X, Y;
        cin >> X >> Y;

        int total = 10 * X + 90 * Y;
        cout << total << endl;
    }

    return 0;
}
