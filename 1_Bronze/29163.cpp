#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int cntOdd = 0, cntEven = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num % 2 == 1)
            cntOdd++;
        else
            cntEven++;
    }
    if (cntOdd < cntEven) {
        cout << "Happy\n";
    } else {
        cout << "Sad\n";
    }
}