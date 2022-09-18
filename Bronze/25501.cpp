#include <iostream>
#include <string>

using namespace std;

int cnt;

int recursion(string& s, int l, int r) {
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(string& s) {
    cnt = 0;
    return recursion(s, 0, s.size() - 1);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        cout << isPalindrome(str) << " " << cnt << "\n";
    }
}