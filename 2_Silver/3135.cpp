#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    int hz[5];
    for (int i = 0; i < n; i++)
        cin >> hz[i];

    int min = abs(b - a);
    for (int i = 0; i < n; i++) {
        int sub = abs(b - hz[i]) + 1;
        min = sub < min ? sub : min;
    }

    cout << min;
}