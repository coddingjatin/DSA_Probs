#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string prev, curr;
    int groups = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> curr;
        if (i == 0 || curr != prev) {
            groups++;
        }
        prev = curr;
    }
    
    cout << groups;
    
    return 0;
}
