#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n <= 2) {
            cout << 2 << "\n";
            continue;
        }
        long long i = n;
        while (true) {
            bool flag = true;
            for (long long j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << i << "\n";
                break;
            }
            i++;
        }
    }
}