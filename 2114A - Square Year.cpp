#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int num = stoi(s);       
        int r = sqrt(num);         

        if (r * r == num) {
            cout << 0 << " " << r << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
