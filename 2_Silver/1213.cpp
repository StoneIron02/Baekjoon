#include <iostream>
#include <string>
#include <deque>

int cnt[26];

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    for (char c : str) {
        cnt[c - 'A']++;
    }

    deque<char> palindrome;

    if (str.size() % 2 == 1) {
        bool flag = false;
        for (int i = 25; i >= 0; i--) {
            if (cnt[i] % 2 == 1) {
                if (!flag) {
                    palindrome.push_front(i + 'A');
                    cnt[i]--;
                    flag = true;
                } else {
                    cout << "I'm Sorry Hansoo";
                    exit(0);
                }
            }
        }
        if (!flag) {
            cout << "I'm Sorry Hansoo";
            exit(0);
        }
    }

    for (int i = 25; i >= 0; i--) {
        if (cnt[i] % 2 == 1) {
            cout << "I'm Sorry Hansoo";
            exit(0);
        }
        for (int j = 0; j < cnt[i] / 2; j++) {
            palindrome.push_front(i + 'A');
            palindrome.push_back(i + 'A');
        }
    }

    for (char c : palindrome)
        cout << c;
}