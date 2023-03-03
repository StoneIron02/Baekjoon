#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        if (b > a) {
            int temp = b;
            b = a;
            a = temp;
        }
        cin >> a >> b;
        int g = gcd(a, b);
        cout << (a * b / g) << "\n";
        cout << g << " ";
    }
}