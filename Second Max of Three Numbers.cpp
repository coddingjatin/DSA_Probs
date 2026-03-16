#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        int second;
        if ((a > b && a < c) || (a < b && a > c))
            second = a;
        else if ((b > a && b < c) || (b < a && b > c))
            second = b;
        else
            second = c;
        cout << second << endl;
    }
    return 0;
}
