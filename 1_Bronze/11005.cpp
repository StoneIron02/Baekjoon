#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    int b;
    cin >> n >> b;

    string s;
    while (n > 0) {
        int d = n % b;
        if (d < 10)
            s = (char)(d + '0') + s;
        else
            s = (char)(d + 'A' - 10) + s;
        n /= b;
    }
    cout << s;
}