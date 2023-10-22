#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c, r;
        cin >> c >> r;
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cout << 'X';
            }
            cout << '\n';
        }
        cout << "\n";
    }
}