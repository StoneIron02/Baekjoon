#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    char c;
    while (cin >> c) {
        if (c == 'C' || c == 'A' || c == 'M' || c == 'B' || c == 'R' || c == 'I' || c == 'D' || c == 'G' || c == 'E')
            continue;
        cout << c;
    }
}