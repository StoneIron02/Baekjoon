#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<int> nums(1);
    cin >> nums[0];
    for (int i = 1; i < n; i++) {
      int num;
      cin >> num;
      if (num == nums.back()) continue;
      nums.push_back(num);
    }
    for (int i : nums) {
      cout << i << " ";
    }
    cout << "$\n";
  }
}