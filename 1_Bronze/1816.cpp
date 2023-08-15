#include <iostream>

using namespace std;

void cal(long long num) {
    for (int i = 2; i <= 1'000'000; i++) {
        if (num % i == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        long long num;
        cin >> num;
        cal(num);
    }
}