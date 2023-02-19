#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

map<char, int> words;

struct comp {
    bool operator()(string str1, string str2) {
        for (int i = 0, j = 0; i < str1.size(), j < str2.size(); i++, j++) {
            int hash1, hash2;
            if (i < str1.size() - 1 && str1[i] == 'n' && str1[i + 1] == 'g') {
                hash1 = 11;
                i++;
            }
            else
                hash1 = words[str1[i]];

            if (i < str2.size() - 1 && str2[j] == 'n' && str2[j + 1] == 'g') {
                hash2 = 11;
                j++;
            }
            else
                hash2 = words[str2[j]];

            if (hash1 != hash2)
                return hash1 > hash2;
        }
        return str1.size() > str2.size();
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    words.emplace('a', 0);
    words.emplace('b', 1);
    words.emplace('k', 2);
    words.emplace('d', 3);
    words.emplace('e', 4);
    words.emplace('g', 5);
    words.emplace('h', 6);
    words.emplace('i', 7);
    words.emplace('l', 8);
    words.emplace('m', 9);
    words.emplace('n', 10);
    words.emplace('o', 12);
    words.emplace('p', 13);
    words.emplace('r', 14);
    words.emplace('s', 15);
    words.emplace('t', 16);
    words.emplace('u', 17);
    words.emplace('w', 18);
    words.emplace('y', 19);

    int n;
    cin >> n;
    priority_queue<string, vector<string>, comp> pq;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        pq.push(str);
    }

    while (!pq.empty()) {
        string str = pq.top();
        pq.pop();
        cout << str << "\n";
    }
}