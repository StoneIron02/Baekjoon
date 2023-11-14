#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int k, n, m;
    cin >> k >> n >> m;
    int sum = k * n;
    int diff = sum - m;
    if (diff < 0)
        diff = 0;
    cout << diff;
}