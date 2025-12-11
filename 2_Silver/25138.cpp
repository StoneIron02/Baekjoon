#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<string> w(N);
  vector<vector<int>> key(N);

  auto mp = [&](char c) {
    if (c == 'a')
      return 0;
    if (c == 'b')
      return 1;
    if (c == 'c')
      return 2;
    if (c == 'd')
      return 3;
    if (c == 'e')
      return 4;
    if (c == 'f')
      return 5;
    if (c == 'g')
      return 6;
    if (c == 'h')
      return 7;
    if (c == 'i')
      return 8;
    if (c == 'j')
      return 9;
    if (c == 'k')
      return 10;
    if (c == 'l')
      return 11;
    if (c == 'm')
      return 13;
    if (c == 'n')
      return 14;
    if (c == 'o')
      return 16;
    if (c == 'p')
      return 17;
    if (c == 'r')
      return 18;
    if (c == 's')
      return 19;
    if (c == 't')
      return 20;
    if (c == 'u')
      return 21;
    if (c == 'v')
      return 22;
    return 23;
  };

  for (int i = 0; i < N; ++i) {
    cin >> w[i];
    auto &k = key[i];
    for (int j = 0; j < (int)w[i].size();) {
      if (j + 1 < (int)w[i].size() && w[i][j] == 'l' && w[i][j + 1] == 'j') {
        k.push_back(12);
        j += 2;
      }
      else if (j + 1 < (int)w[i].size() && w[i][j] == 'n' && w[i][j + 1] == 'j') {
        k.push_back(15);
        j += 2;
      }
      else {
        k.push_back(mp(w[i][j]));
        j++;
      }
    }
  }

  vector<int> idx(N);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int a, int b) {
    return key[a] < key[b];
  });

  for (int i : idx)
    cout << w[i] << '\n';
}
