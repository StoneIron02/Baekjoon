#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> words;
    while (true) {
        string word;
        cin >> word;
        if (word == "-") break;
        vector<int> alphabet(26);
        for (char c : word)
            alphabet[c - 'A']++;
        words.push_back(alphabet);
    }

    while (true) {
        string board;
        cin >> board;
        if (board == "#") break;
        vector<int> alphabet(26);
        for (char c : board)
            alphabet[c - 'A']++;

        // 만들 수 있는 단어인지 우선 체크
        vector<vector<int>> partWords;
        for (vector<int>& word : words) {
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (word[i] > alphabet[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                partWords.push_back(word);
        }

        // 중앙에 오는 알파벳에 따라 만들 수 있는 단어 체크
        int maxCnt = -1, minCnt = 200'001;
        vector<int> maxList, minList;
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] > 0) {
                int cnt = 0;
                for (vector<int>& word : partWords) {
                    if (word[i] > 0)
                        cnt++;
                }
                if (maxCnt <= cnt) {
                    if (maxCnt < cnt) {
                        maxCnt = cnt;
                        maxList.clear();
                    }
                    maxList.push_back(i);
                }
                if (minCnt >= cnt) {
                    if (minCnt > cnt) {
                        minCnt = cnt;
                        minList.clear();
                    }
                    minList.push_back(i);
                }
            }
        }

        for (int ans : minList)
            cout << (char)(ans + 'A');
        cout << " " << minCnt << " ";
        for (int ans : maxList)
            cout << (char)(ans + 'A');
        cout << " " << maxCnt << "\n";
    }
}