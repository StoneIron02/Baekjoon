#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n1, k1, n2, k2;
    cin >> n1 >> k1 >> n2 >> k2;
    cout << (n1 * k1 + n2 * k2);

}