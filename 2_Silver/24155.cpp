#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  pii arr[100000];
  int rank[100000];
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr[i] = {num, i};
  }
  sort(arr, arr + n, greater<>());
  int curRank = 0;
  int curScore = 101;
  for (int i = 0; i < n; i++) {
    if (curScore > arr[i].first) {
      curScore = arr[i].first;
      curRank = i + 1;
    }
    rank[arr[i].second] = curRank;
  }
  for (int i = 0; i < n; i++) {
    cout << rank[i] << "\n";
  }
}