#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int add, sub;
    cin >> add >> sub;
    if (add < sub) {
        cout << -1;
        return 0;
    }
    int p = add + sub;
    int m = add - sub;
    if (p % 2 != 0 || m % 2 != 0) {
        cout << -1;
        return 0;
    }
    int p2 = p / 2;
    int m2 = m / 2;
    cout << max(p2, m2) << " " << min(p2, m2);
}