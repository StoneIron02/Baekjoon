#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

pii arr[500'000];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr[i] = {num, i};
    }
    sort(arr, arr + N);

    int maxCnt = 0;
    for (int i = 0; i < N; i++) {
        maxCnt = max(maxCnt, arr[i].second - i);
    }

    cout << (maxCnt + 1);
}