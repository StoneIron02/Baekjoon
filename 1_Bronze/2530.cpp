#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    int d;
    cin >> d;

    int now = a * 60 * 60 + b * 60 + c;
    int result = now + d;

    int result_hour = result / (60 * 60) % 24;
    int result_min = result % (60 * 60) / 60;
    int result_sec = result % (60 * 60) % 60;

    cout << result_hour << " " << result_min << " " << result_sec;
}