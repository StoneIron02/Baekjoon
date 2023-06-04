#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            return 0;

        if (a > b) {
            if (a > c) {
                if (a >= b + c) {
                    cout << "Invalid\n";
                    continue;
                }
            } else {
                if (c >= a + b) {
                    cout << "Invalid\n";
                    continue;
                }
            }
        } else {
            if (b > c) {
                if (b >= a + c) {
                    cout << "Invalid\n";
                    continue;
                }
            } else {
                if (c >= a + b) {
                    cout << "Invalid\n";
                    continue;
                }
            }
        }

        if (a == b) {
            if (a == c) {
                cout << "Equilateral\n";
            } else {
                cout << "Isosceles\n";
            }
        } else if (a == c) {
            cout << "Isosceles\n";
        } else if (b == c) {
            cout << "Isosceles\n";
        } else {
            cout << "Scalene\n";
        }
    }
}