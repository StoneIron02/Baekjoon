#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    char c;
    cin >> c;
    if (c == 'M') {
        cout << "MatKor";
    } else if (c == 'W') {
        cout << "WiCys";
    } else if (c == 'C') {
        cout << "CyKor";
    } else if (c == 'A') {
        cout << "AlKor";
    } else {
        cout << "$clear";
    }
}