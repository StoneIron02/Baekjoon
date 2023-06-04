#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int L = lcm(M, N);
        bool flag = false;
        for (int result = x; result <= L; result += M) {
            int cal = result % N;
            if (cal == 0)
                cal += N;
            if (cal == y) {
                cout << result << "\n";
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << -1 << "\n";
    }
}