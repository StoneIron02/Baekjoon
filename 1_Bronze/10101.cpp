#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum != 180)
        cout << "Error";
    else {
        if (a == b) {
            if (a == c) {
                cout << "Equilateral";
            } else {
                cout << "Isosceles";
            }
        } else if (a == c) {
            cout << "Isosceles";
        } else if (b == c) {
            cout << "Isosceles";
        } else {
            cout << "Scalene";
        }
    }
}