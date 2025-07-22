#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  vector<int> nums;
  int n;
  while (cin >> n) {
    nums.push_back(n);
  }

  for (int k = 0; k < nums.size(); ++k) {
    int N = nums[k];
    for (int i = 0; i < N; ++i) {
      int left = i;
      int right = 2 * N - 2 - i;

      for (int j = 0; j <= right; ++j) {
        if (j == left || j == right)
          cout << '*';
        else
          cout << ' ';
      }
      cout << '\n';
    }
  }
}