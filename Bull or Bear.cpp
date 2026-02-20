#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int X, Y;
        cin >> X >> Y;
        if (Y > X) {
            cout << "PROFIT" << endl;
        } 
        else if (Y < X) {
            cout << "LOSS" << endl;
        } 
        else {
            cout << "NEUTRAL" << endl;
        }
    }
    return 0;
}
