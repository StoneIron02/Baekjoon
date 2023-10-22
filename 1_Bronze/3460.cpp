#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int i = 0;
        while (n > 0) {
            int cur = n % 2;
            if (cur == 1)
                cout << i << " ";
            n /= 2;
            i++;
        }
        cout << "\n";
    }
}