#include <iostream>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, current = 0, longest = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (a == 0) {
                current++;
                if (current > longest) longest = current;
            } else {
                current = 0;
            }
        }
        cout << longest << endl;
    }
    return 0;
}
