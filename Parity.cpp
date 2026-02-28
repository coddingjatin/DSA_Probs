#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        if (N % 2 == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
    return 0;
}
