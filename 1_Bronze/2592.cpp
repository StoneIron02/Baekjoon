#include <iostream>

using namespace std;

int cnt[1000];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        sum += num;
        cnt[num]++;
    }
    int M = 0;
    for (int i = 0; i < 1000; i += 10) {
        if (cnt[M] < cnt[i]) {
            M = i;
        }
    }
    cout << (sum / 10) << "\n";
    cout << M;
}