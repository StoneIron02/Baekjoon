#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int cur = 1;
    int sec = 0;
    while (true) {
        if (n == 0) {
            cout << sec;
            return 0;
        }
        else if (n < cur) {
            cur = 1;
            continue;
        }
        else {
            n -= cur++;
            sec++;
        }
    }
}