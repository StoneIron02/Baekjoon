#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        if (num % 2 == 0) {
            cout << num << " is even\n";
        } else {
            cout << num << " is odd\n";
        }
    }
}