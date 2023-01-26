#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long min, max;
    cin >> min >> max;

    vector<bool> arr(1'000'001);
    vector<bool> sqr(1'000'001);
    for (int i = 0; i < 1'000'001; i++) {
        arr[i] = false;
        sqr[i] = false;
    }

    for (int i = 2; i <= 1'000'001; i++) {
        if (sqr[i]) continue;

        for (int j = i; j < 1'000'001; j += i) {
            sqr[j] = true;
        }
        long long num = (long long)i * i;
        long long idx = min % num;
        if (idx != 0) idx = num - idx;
        for (long long j = idx; j < 1'000'001; j += num) {
            arr[j] = true;
        }
    }

    int cnt = 0;
    for (int i = 0; i <= max - min; i++) {
        if (!arr[i])
            cnt++;
    }
    cout << cnt;
}