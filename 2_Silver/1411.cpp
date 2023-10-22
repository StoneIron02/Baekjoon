#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string result[100];
    for (int i = 0; i < n; i++) {
        string origin;
        cin >> origin;
        string change;
        int num = 0;
        map<char, char> map;
        for (char c : origin) {
            if (map[c] == 0) {
                map[c] = (char)('a' + num++);
            }
            change += map[c];
        }
        result[i] = change;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (result[i] == result[j])
                cnt++;
        }
    }

    cout << cnt;
}