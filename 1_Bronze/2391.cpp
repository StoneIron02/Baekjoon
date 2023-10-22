#include <iostream>
#include <queue>

using namespace std;

string words[10000];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int w;
        cin >> w;
        for (int i = 0; i < w; i++)
            cin >> words[i];

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < w; i++) {
            int cnt = 0;
            for (int j = 0; j < str.size(); j++) {
                if (str[j] != words[i][j])
                    cnt++;
            }
            pq.push({cnt, i});
        }

        cout << words[pq.top().second] << "\n";
    }
}