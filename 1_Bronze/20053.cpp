#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int& i : arr) {
      cin >> i;
    }
    sort(arr.begin(), arr.end());
    cout << arr.front() << " " << arr.back() << "\n";
  }
}