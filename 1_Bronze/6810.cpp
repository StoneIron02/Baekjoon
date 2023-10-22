#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str = "9780921418";
    for (int i = 0; i < 3; i++) {
        char c;
        cin >> c;
        str += c;
    }

    int sum = 0;
    bool one = true;
    for (char c : str) {
        int n = c - '0';
        if (one) {
            sum += n * 1;
        } else {
            sum += n * 3;
        }
        one = !one;
    }

    cout << "The 1-3-sum is " << sum;
}