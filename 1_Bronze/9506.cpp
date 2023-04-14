#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (n == -1)
            break;
        vector<int> divisor;
        int sum = 1;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                divisor.push_back(i);
                sum += i;
            }
        }
        if (sum == n) {
            cout << n << " = 1 + ";
            for (int i : divisor) {
                if (divisor[divisor.size() - 1] == i)
                    cout << i << "\n";
                else
                    cout << i << " + ";
            }
        } else {
            cout << n << " is NOT perfect.\n";
        }
    }
}