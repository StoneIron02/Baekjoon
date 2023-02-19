#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int sumOdd = 0;
    int minOdd = 100;
    for (int i = 0; i < 7; i++) {
        int num;
        cin >> num;
        if (num % 2 == 1) {
            sumOdd += num;
            minOdd = num < minOdd ? num : minOdd;
        }
    }
    if (sumOdd == 0) {
        cout << "-1";
        exit(0);
    }
    cout << sumOdd << "\n";
    cout << minOdd << "\n";
}