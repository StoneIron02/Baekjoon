#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, s;
    while (cin >> n >> s) {
        n += 1;
        cout << (s / n) << "\n";
    }
}