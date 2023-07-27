#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int sum = 0;
    string str;
    cin >> str;
    for (char c : str) {
        if (c >= 'a' && c <= 'z')
            sum += (c - 'a' + 1);
        else
            sum += (c - 'A' + 27);
    }

    if (sum == 1) {
        cout << "It is a prime word.";
        return 0;
    }
    for (int i = 2; i < sum; i++) {
        if (sum % i == 0) {
            cout << "It is not a prime word.";
            return 0;
        }
    }
    cout << "It is a prime word.";
}