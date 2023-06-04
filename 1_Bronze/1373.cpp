#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string binary_s;
    cin >> binary_s;
    string octal_s = "";
    if (binary_s == "0") {
        cout << "0";
        return 0;
    }
    while (binary_s.size() % 3 != 0) {
        binary_s = "0" + binary_s;
    }
    for (int i = 0; i < binary_s.size(); i += 3) {
        int oct = 0;
        for (int j = 0; j < 3; j++) {
            int b = binary_s[i + j] - '0';
            oct *= 2;
            oct += b;
        }
        octal_s += to_string(oct);
    }
    cout << octal_s;
}