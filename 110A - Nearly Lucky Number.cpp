#include <iostream>
using namespace std;

int main() {
    string n;
    cin >> n;

    int cnt = 0;
    for (char c : n) {
        if (c == '4' || c == '7')
            cnt++;
    }

    if (cnt == 4 || cnt == 7)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
