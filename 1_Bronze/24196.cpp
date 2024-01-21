#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    string result;
    int i = 0;
    while (i < str.size() - 1) {
        result += str[i];
        i += str[i] - 'A' + 1;
    }
    result += str[i];
    cout << result;
}