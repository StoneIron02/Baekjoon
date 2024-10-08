#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<int> A;
    vector<int> B;
    A.resize(N);
    B.resize(M);
    for (int& i : A) {
      cin >> i;
    }
    for (int& i : B) {
      cin >> i;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int sum = 0;
    for (int& i : A) {
      auto pos = lower_bound(B.begin(), B.end(), i);
      sum += pos - B.begin();
    }
    cout << sum << "\n";
  }
}
