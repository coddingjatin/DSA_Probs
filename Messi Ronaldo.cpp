#include <iostream>
using namespace std;

int main() {
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;

    int messiPoints = 2 * A + B;
    int ronaldoPoints = 2 * X + Y;

    if (messiPoints > ronaldoPoints)
        cout << "Messi";
    else if (ronaldoPoints > messiPoints)
        cout << "Ronaldo";
    else
        cout << "Equal";

    return 0;
}
