#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        for (int i = 0; i < num; i++)
            cout << "=";
        cout << "\n";
    }
}