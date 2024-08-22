#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  vector<int> arr(n);
  int before = 0;
  int cnt = 0;
  for (int& i : arr) {
    cin >> i;
    if (i <= before) {
      cnt++;
    }
    before = i;
  }
  if (arr[0] <= arr[n - 1]) {
    cnt++;
  }
  cout << cnt;
}
