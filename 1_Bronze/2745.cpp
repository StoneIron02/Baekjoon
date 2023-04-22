#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string n;
    int b;
    cin >> n >> b;

    int n_10 = 0;
    for (char c : n) {
        n_10 *= b;
        if (c >= '0' && c <= '9')
            n_10 += c - '0';
        else
            n_10 += c - 'A' + 10;
    }
    cout << n_10;
}