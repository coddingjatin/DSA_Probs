#include <iostream>
#include <set>
using namespace std;

int main() {
    string username;
    cin>>username;
    set<char> s;
    for (char c : username) {
        s.insert(c);
    }
    if (s.size() % 2 == 0) {
        cout << "CHAT WITH HER!";
    } else {
        cout << "IGNORE HIM!";
    }

    return 0;
}

