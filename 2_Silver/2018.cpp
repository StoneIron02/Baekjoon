#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int cnt = 0;
    int i = 1, j = 1, sum = 1;
    while (i <= n) {
        if (sum < n) {
            sum += ++j;
        }
        else {
            if (sum == n)
                cnt++;
            sum -= i++;
        }
    }
    cout << cnt;
}