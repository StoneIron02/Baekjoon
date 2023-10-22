#include <iostream>
#include <set>

using namespace std;

bool check(string& origin, string& compare) {
    for (int i = 0; i < origin.size(); i++) {
        string newStr = origin.substr(i) + origin.substr(0, i);
        bool isSame = true;
        for (int j = 0; j < newStr.size(); j++) {
            if (newStr[j] != compare[j]) {
                isSame = false;
                break;
            }
        }
        if (isSame) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    set<string> words;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        bool flag = false;
        for (auto word : words) {
            if (word.size() != str.size()) {
                continue;
            }
            if (check(word, str)) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        words.insert(str);
    }
    cout << words.size();
}