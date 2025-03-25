#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> heights(N);
  for (int i = 0; i < N; i++) {
    cin >> heights[i];
  }

  for (int i = 0; i < N - 3; i++) {
    if (heights[0] < heights[N - 1]) {
      heights[N - 1]--;
    } else {
      heights[0]--;
    }
  }

  cout << max(heights[0], heights[N - 1]) - 1;
}