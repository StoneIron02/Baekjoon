#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

    string S, P;
    cin >> S >> P;

    map<char, list<int>> charList;
    for (int i = 0; i < S.size(); i++) {
        charList[S[i]].push_back(i);
    }

    int cnt = 0;
    for (int i = 0; i < P.size(); i++) {
        list<int>& indexList = charList[P[i]];
        int maxMatch = -1;
        for (int index : indexList) {
            int match = 0;
            for (int j = 1; index + j < S.size(); j++, ++match)
                if (S[index + j] != P[i + j]) break;
            maxMatch = match > maxMatch ? match : maxMatch;
        }
        i += maxMatch;
        cnt++;
    }

    cout << cnt;
}