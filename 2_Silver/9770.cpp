#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  vector<int> arr;
  int num;
  while (cin >> num) {
    arr.push_back(num);
  }
  if (arr.size() == 1) {
    cout << arr[0];
    exit(0);
  }
  int maxGCD = -1;
  for (int i = 0; i < arr.size() - 1; i++) {
    for (int j = i + 1; j < arr.size(); j++) {
      maxGCD = max(maxGCD, gcd(arr[i], arr[j]));
    }
  }
  cout << maxGCD;
}