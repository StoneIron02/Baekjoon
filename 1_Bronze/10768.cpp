#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int month, day;
    cin >> month >> day;

    if (month < 2) {
        cout << "Before";
    } else if (month > 2) {
        cout << "After";
    } else {
        if (day < 18)
            cout << "Before";
        else if (day > 18)
            cout << "After";
        else
            cout << "Special";
    }
}