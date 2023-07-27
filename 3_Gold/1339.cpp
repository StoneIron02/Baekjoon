#include <iostream>
#include <algorithm>

using namespace std;

int n;
int countSymbol[26];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        int w = 1;
        for (int j = word.size() - 1; j >= 0; j--) {
            char c = word[j];
            countSymbol[c - 'A'] += w;
            w *= 10;
        }
    }

    sort(countSymbol, countSymbol + 26, greater<>());
    int sum = 0;
    int num = 9;
    for (int i = 0; i < 26; i++) {
        if (countSymbol[i] == 0)
            break;
        sum += countSymbol[i] * num--;
    }
    cout << sum;
}