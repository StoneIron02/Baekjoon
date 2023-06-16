#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int indeg[1001];
bool visit[1001];
bool matrix[1001][1001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    fill(indeg, indeg + N, 0);
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        if (num == 0)
            continue;
        int a, b;
        cin >> a;
        for (int j = 1; j < num; j++) {
            cin >> b;
            if (!matrix[a][b]) {
                matrix[a][b] = true;
                indeg[b]++;
            }
            a = b;
        }
    }

    vector<int> result;
    for (int t = 0; t < N; t++) {
        bool flag = false;
        for (int i = 1; i <= N; i++) {
            if (indeg[i] == 0 && !visit[i]) {
                flag = true;
                visit[i] = true;
                result.push_back(i);
                for (int j = 1; j <= N; j++) {
                    if (matrix[i][j]) {
                        matrix[i][j] = false;
                        indeg[j]--;
                    }
                }
                break;
            }
        }
        if (!flag) { // cycle
            cout << 0;
            return 0;
        }
    }

    for (auto i : result) {
        cout << i << "\n";
    }
}