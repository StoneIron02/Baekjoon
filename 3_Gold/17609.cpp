#include <iostream>
#include <string>
using namespace std;

int check_palindrome(string str, bool flag) {
    int n = str.size();
    if (n == 1)
        return 0;
    int i = 0, j = n - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            if (flag) return 1;
            int nSubstr = j - i;
            int a = check_palindrome(str.substr(i + 1, nSubstr), true);
            int b = check_palindrome(str.substr(i, nSubstr), true);
            return 1 + min(a, b);
        }
        i++;
        j--;
    }
    return 0;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        cout << check_palindrome(str, false) << "\n";
    }
}