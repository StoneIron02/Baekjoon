#include <iostream>

using namespace std;

int rev(int num) {
    int result = 0;
    while (num > 0) {
        result *= 10;
        result += num % 10;
        num /= 10;
    }
    return result;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;
    int sum = rev(x) + rev(y);
    cout << rev(sum);
}