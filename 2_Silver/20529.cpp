#include <iostream>
#include <map>

using namespace std;

string mapping[16] = {"ISTJ", "ISFJ", "INFJ", "INTJ",
                      "ISTP", "ISFP", "INFP", "INTP",
                      "ESTP", "ESFP", "ENFP", "ENTP",
                      "ESTJ", "ESFJ", "ENFJ", "ENTJ"};
int dist[16][16];
int arr[100'000];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    map<string, int> revMapping;
    revMapping.insert({"ISTJ", 0});
    revMapping.insert({"ISFJ", 1});
    revMapping.insert({"INFJ", 2});
    revMapping.insert({"INTJ", 3});
    revMapping.insert({"ISTP", 4});
    revMapping.insert({"ISFP", 5});
    revMapping.insert({"INFP", 6});
    revMapping.insert({"INTP", 7});
    revMapping.insert({"ESTP", 8});
    revMapping.insert({"ESFP", 9});
    revMapping.insert({"ENFP", 10});
    revMapping.insert({"ENTP", 11});
    revMapping.insert({"ESTJ", 12});
    revMapping.insert({"ESFJ", 13});
    revMapping.insert({"ENFJ", 14});
    revMapping.insert({"ENTJ", 15});

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            string mbti1 = mapping[i];
            string mbti2 = mapping[j];
            int cnt = 0;
            for (int t = 0; t < 4; t++) {
                if (mbti1[t] != mbti2[t])
                    cnt++;
            }
            dist[i][j] = cnt;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;

        int mbtiCnt[16];
        for (int i = 0; i < 16; i++)
            mbtiCnt[i] = 0;

        cin >> n;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            string mbti;
            cin >> mbti;
            int m = revMapping[mbti];
            if (mbtiCnt[m] >= 3) {
                flag = true;
            } else {
                mbtiCnt[m]++;
                arr[i] = m;
            }
        }

        if (flag) {
            cout << 0 << "\n";
            continue;
        }

        int minDist = 12;
        for (int i = 0; i < n; i++) {
            int a = arr[i];
            for (int j = 1; j < n; j++) {
                if (i == j) continue;
                int b = arr[j];
                for (int k = 2; k < n; k++) {
                    if (i == k) continue;
                    if (j == k) continue;
                    int c = arr[k];
                    minDist = min(minDist, dist[a][b] + dist[b][c] + dist[c][a]);
                }
            }
        }
        cout << minDist << "\n";
    }
}