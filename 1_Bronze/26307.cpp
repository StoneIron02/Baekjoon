#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int h, m;
    cin >> h >> m;
    m += h * 60;
    m -= 9 * 60;
    cout << m;
}