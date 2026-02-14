#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int p[101], ans[101];
 
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
 
    for(int i = 1; i <= n; i++) {
        ans[p[i]] = i;
    }
 
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
 
    return 0;
}
