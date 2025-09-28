#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N, D; 
  cin >> N >> D;
  vector<string> arr(N);
  for (int i = 0; i < N; ++i) cin >> arr[i];

  auto up_down = [](char c) -> char { // 상하
    switch (c) {
    case 'd': return 'q';
    case 'b': return 'p';
    case 'q': return 'd';
    case 'p': return 'b';
    }
    return c;
  };
  auto left_right = [](char c) -> char { // 좌우
    switch (c) {
    case 'd': return 'b';
    case 'b': return 'd';
    case 'q': return 'p';
    case 'p': return 'q';
    }
    return c;
  };

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      arr[i][j] = (D == 1) ? up_down(arr[i][j]) : left_right(arr[i][j]);
    }
    cout << arr[i] << '\n';
  }
}