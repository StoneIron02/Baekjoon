#include <iostream>

using namespace std;

bool isGMS(int num) {
    string numStr = to_string(num);
    for (char c : numStr) {
        if (!(c == '4' || c == '7'))
            return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = n; i >= 4; i--) {
        if (isGMS(i)) {
            cout << i;
            return 0;
        }
    }
}