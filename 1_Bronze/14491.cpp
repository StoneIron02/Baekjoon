#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    string result;
    while (t > 0) {
        result = to_string(t % 9) + result;
        t /= 9;
    }
    cout << result;
}