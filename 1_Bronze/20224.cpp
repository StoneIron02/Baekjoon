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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int cnt = 0;
    for (int i = 0; i + 3 < n; ++i)
      if (arr[i] == 2 && arr[i + 1] == 0 && arr[i + 2] == 2 && arr[i + 3] == 0)
        cnt++;
    cout << cnt << '\n';
  }
}
