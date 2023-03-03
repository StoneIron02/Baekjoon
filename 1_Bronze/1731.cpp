#include <iostream>

using namespace std;

int num[50];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int d1 = num[1] - num[0];
    int d2 = num[2] - num[1];
    if (d1 == d2) {
        cout << num[n - 1] + d1;
    } else {
        int r = num[1] / num[0];
        cout << num[n - 1] * r;
    }
}