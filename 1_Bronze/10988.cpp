#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    int i = 0, j = str.size() - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            cout << 0;
            exit(0);
        }
        i++;
        j--;
    }
    cout << 1;
}