#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

vector<int> compute_failure(string pattern) {
    int m = pattern.size();
    vector<int> failure(m);
    failure[0] = 0;
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = failure[j-1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        failure[i] = j;
    }
    return failure;
}

// KMP 알고리즘을 수행하는 함수
void kmp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> failure = compute_failure(pattern);
    vector<int> matches;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = failure[j-1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            cnt++;
            j = failure[j-1];
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    int m;
    string s;
    cin >> n;
    cin >> m;
    cin >> s;

    string NStr = "I";
    for (int i = 0; i < n; i++) {
        NStr += "OI";
    }

    kmp(s, NStr);

    cout << cnt;
}