#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a, b;
    int current = 0;
    int capacity = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        current -= a;
        current += b;
        if (current > capacity) {
            capacity = current;
        }
    }
    
    cout << capacity;
    
    return 0;
}
