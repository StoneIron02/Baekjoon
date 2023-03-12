#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    priority_queue<string, vector<string>, greater<>> words;
    for (int i = 0; i < str.size() - 2; i++) {
        for (int j = i + 1; j < str.size() - 1; j++) {
            string newStr;
            for (int k = i; k >= 0; k--)
                newStr += str[k];
            for (int k = j; k > i; k--)
                newStr += str[k];
            for (int k = str.size() - 1; k > j; k--)
                newStr += str[k];
            words.push(newStr);
        }
    }
    cout << words.top();
}