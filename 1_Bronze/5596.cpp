#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int sum[2] {0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            int num;
            cin >> num;
            sum[i] += num;
        }
    }

    cout << (sum[0] >= sum[1] ? sum[0] : sum[1]);
}