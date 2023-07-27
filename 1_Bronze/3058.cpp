#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int sum = 0;
        int m = INT32_MAX;
        for (int i = 0; i < 7; i++) {
            int num;
            cin >> num;
            if (num % 2 == 0) {
                sum += num;
                m = min(m, num);
            }
        }
        cout << sum << " " << m << "\n";
    }
}