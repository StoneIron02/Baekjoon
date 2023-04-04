#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    int arr[100000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int g = arr[1] - arr[0];
    for (int i = 1; i < n - 1; i++) {
        g = gcd(g, arr[i + 1] - arr[i]);
    }

    int i = 1, num = arr[0], result = 0;
    while (i < n) {
        if (num + g != arr[i])
            result++;
        else
            i++;
        num += g;
    }
    cout << result;
}