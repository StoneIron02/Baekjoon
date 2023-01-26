#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> alphabets(26);

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int idx = str[0] - 'a';
        alphabets[idx]++;
    }

    bool flag = false;
    for (int i = 0; i < 26; i++) {
        if (alphabets[i] >= 5) {
            flag = true;
            cout << (char)(i + 'a');
        }
    }
    if (!flag)
        cout << "PREDAJA";
}