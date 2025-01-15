#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string T;
  cin >> T;
  string P = "DKSH";
  int cnt = 0;
  auto searcher = default_searcher(P.begin(), P.end());
  auto it = T.begin();
  while ((it = search(it, T.end(), searcher)) != T.end()) {
    cnt++;
    it += P.size();
  }
  cout << cnt;
}