#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int arr[10001];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum += abs(arr[i] - arr[j]);
        }
    }
    cout << sum;
}