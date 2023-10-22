#include <iostream>
#include <vector>

using namespace std;

int cnt[26];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    char c;
    while ((c = cin.get()) != EOF) {
        if (c == ' ' || c == '\n') continue;
        cnt[c - 'a']++;
    }

    int maxCnt = -1;
    vector<char> maxAlphabet;
    for (int i = 0; i < 26; i++) {
        if (maxCnt < cnt[i]) {
            maxCnt = cnt[i];
            maxAlphabet.clear();
        }
        if (maxCnt == cnt[i]) {
            maxAlphabet.push_back(i + 'a');
        }
    }

    for (char i : maxAlphabet) {
        cout << i;
    }
}