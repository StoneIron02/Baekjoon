#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long a, b;
    cin >> a >> b;

    long long num;
    cin >> num;

    long long result = a + b;
    if (result >= num * 2) {
        result -= num * 2;
    }

    cout << result;
}