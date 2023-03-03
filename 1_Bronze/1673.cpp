#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n, k;
    while (cin >> n >> k) {
        long long cnt = 0;
        while (n >= k) {
            cnt += (n / k) * k;
            n = (n % k) + (n / k);
        }
        cnt += n;
        cout << cnt << "\n";
    }
}