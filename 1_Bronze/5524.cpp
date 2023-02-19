#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] <= 'Z')
                str[j] = str[j] - 'A' + 'a';
        }
        cout << str << "\n";
    }
}