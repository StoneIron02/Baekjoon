#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  while (getline(cin, str)) {
    istringstream iss(str);
    vector<int> nums, result;
    int num;
    while (iss >> num) {
      nums.push_back(num);
    }

    int n = nums.size();
    if (n == 0) {
      cout << "\n";
      continue;
    }

    result.resize(n);

    for (int i = 0; i < n; ++i) {
      if (n == 1) {
        result[i] = nums[i];
      } else if (i == 0) {
        result[i] = nums[i] * nums[i + 1];
      } else if (i == n - 1) {
        result[i] = nums[i] * nums[i - 1];
      } else {
        result[i] = nums[i - 1] * nums[i] * nums[i + 1];
      }
    }

    for (int i = 0; i < n; ++i) {
      cout << result[i];
      if (i != n - 1) cout << " ";
    }
    cout << "\n";
  }
}