#include <iostream>
using namespace std;

int min_len(const string& str, int cur_K) {
    int cur_min = str.size();

    for (int i = 0; i < str.size(); ++i) {
        for (int j = 0; j < str.size(); ++j) {
            if (i == j) continue;
            if (str[i] != str[j]) continue;
            if (str[i] == 'X') continue;
            int left = str.size() - (j - i + 1);
            if (cur_K > 1) {
                string sub;
                if (i > 0) sub += str.substr(0, i);
                if (j < str.size() - 1) sub += str.substr(j + 1);
                cur_min = min(cur_min, min_len(sub, cur_K - 1));
            } else {
                cur_min = min(cur_min, left);
            }
        }
    }
    return cur_min;
}

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    cout << min_len(S, K);
}