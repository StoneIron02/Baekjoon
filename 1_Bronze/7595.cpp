#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cout << '*';
            }
            cout << "\n";
        }
    }
}