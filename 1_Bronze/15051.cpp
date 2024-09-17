#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  vector<int> arr(3);
  for (int& i : arr) {
    cin >> i;
  }
  cout << min({arr[1] + arr[2] * 2, arr[0] + arr[2], arr[0] * 2 + arr[1]}) * 2;
}