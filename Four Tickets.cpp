#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int X;
        cin >> X;
        
        if (4 * X <= 1000)
            cout << "YES";
        else
            cout << "NO";
        
        cout << endl;
    }
    
    return 0;
}
