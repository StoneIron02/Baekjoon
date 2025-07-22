#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int M, N;
  cin >> M >> N;
  vector<vector<int>> arr(M, vector<int>(N));

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> arr[i][j];
    }
  }

  map<vector<int>, int> freq;

  for (int i = 0; i < M; ++i) {
    vector<pair<int, int>> tmp;
    for (int j = 0; j < N; ++j) {
      tmp.emplace_back(arr[i][j], j);
    }
    sort(tmp.begin(), tmp.end());

    vector<int> rank(N);
    int cur_rank = 0;
    for (int j = 0; j < N; ++j) {
      if (j > 0 && tmp[j].first != tmp[j - 1].first) {
        ++cur_rank;
      }
      rank[tmp[j].second] = cur_rank;
    }

    freq[rank]++;
  }

  int res = 0;
  for (auto& entry : freq) {
    int count = entry.second;
    if (count >= 2) {
      res += count * (count - 1) / 2;
    }
  }

  cout << res;
}