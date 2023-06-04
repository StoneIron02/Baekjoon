#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        long long a, b;
        cin >> a >> b;
        cout << (a + b) << "\n";
    }
}