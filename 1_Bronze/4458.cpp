#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        if (str[0] >= 'a' && str[0] <= 'z') {
            str[0] = str[0] - 'a' + 'A';
        }
        cout << str << "\n";
    }
}