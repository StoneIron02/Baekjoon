#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int sum1 = c + b;
    int sum2 = a + d;

    cout << min(sum1, sum2);
}