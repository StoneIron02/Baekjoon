#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long sum = 0;
    int first;
    cin >> first;
    sum += first;
    for (int i = 1; i < n; i++) {
        int num;
        cin >> num;
        sum += (num - 1);
    }
    cout << sum;
}