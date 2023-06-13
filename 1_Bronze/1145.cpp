#include <iostream>

using namespace std;

int nums[5];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 5; i++)
        cin >> nums[i];

    int n = 4;
    while (true) {
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (n % nums[i] == 0)
                cnt++;
        }
        if (cnt >= 3) {
            cout << n;
            break;
        }
        n++;
    }
}