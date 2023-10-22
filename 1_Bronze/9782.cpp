#include <iostream>
#include <iomanip>

using namespace std;

int arr[100];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (n % 2 == 0) {
            cout << fixed << setprecision(1) << "Case " << t << ": " << ((1.0 * arr[n / 2 - 1] + arr[n / 2]) / 2) << "\n";
        } else {
            cout << fixed << setprecision(1) << "Case " << t << ": " << (1.0 * arr[n / 2]) << "\n";
        }
        t++;
    }
}