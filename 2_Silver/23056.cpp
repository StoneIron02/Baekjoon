#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, string> pis;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  vector<vector<pis>> teams(N + 1);

  while (true) {
    int num;
    string name;
    cin >> num >> name;
    if (num == 0 && name == "0") break;

    if (teams[num].size() < M) {
      teams[num].emplace_back(num, name);
    }
  }

  for (int i = 1; i <= N; i += 2) {
    sort(teams[i].begin(), teams[i].end(), [](const pis& l, const pis& r) {
      if (l.second.length() == r.second.length())
        return l.second < r.second;
      return l.second.length() < r.second.length();
    });
    for (const auto &student : teams[i]) {
      cout << student.first << " " << student.second << "\n";
    }
  }

  for (int i = 2; i <= N; i += 2) {
    sort(teams[i].begin(), teams[i].end(), [](const pis& l, const pis& r) {
      if (l.second.length() == r.second.length())
        return l.second < r.second;
      return l.second.length() < r.second.length();
    });
    for (const auto &student : teams[i]) {
      cout << student.first << " " << student.second << "\n";
    }
  }
}