#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  unordered_set<int> friends;
  for (int i = 0; i < M; ++i) {
    int fr;
    cin >> fr;
    friends.insert(fr);
  }

  int cnt = 0;
  for (int i = 0; i < M; i++) {
    if (friends.find(arr[i]) == friends.end()) {
      cnt++;
    }
  }

  cout << cnt;
}