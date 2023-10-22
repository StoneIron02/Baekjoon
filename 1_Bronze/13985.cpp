#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    char dummy;
    cin >> a >> dummy >> b >> dummy >> c;
    if (a + b == c) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}