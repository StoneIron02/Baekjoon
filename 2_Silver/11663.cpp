#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dots;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N, M;
  cin >> N >> M;
  dots.resize(N);
  for (int& i : dots) {
    cin >> i;
  }
  sort(dots.begin(), dots.end());

  while (M--) {
    int s, e;
    cin >> s >> e;
    int sIdx = lower_bound(dots.begin(), dots.end(), s) - dots.begin();
    int eIdx = upper_bound(dots.begin(), dots.end(), e) - dots.begin() - 1;
    cout << eIdx - sIdx + 1 << "\n";
  }
}
