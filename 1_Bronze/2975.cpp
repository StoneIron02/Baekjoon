#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        int balance;
        char op;
        int diff;
        cin >> balance >> op >> diff;
        if (balance == 0 && op == 'W' && diff == 0) break;

        int result;
        if (op == 'D') {
            result = balance + diff;
        } else {
            result = balance - diff;
        }

        if (result < -200) {
            cout << "Not allowed\n";
        } else {
            cout << result << "\n";
        }
    }
}