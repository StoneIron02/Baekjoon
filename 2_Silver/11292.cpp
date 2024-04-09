#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  while (cin >> n) {
    if (n == 0) break;
    vector<pair<string, double>> origin(n);
    vector<pair<double, string>> arr(n);
    for (int i = 0; i < n; i++) {
      string a;
      cin >> a;
      double b;
      cin >> b;
      origin[i] = {a, b};
      arr[i] = {b, a};
    }
    sort(arr.begin(), arr.end(), greater<>());
    double maxVal = arr[0].first;
    for (auto& i : origin) {
      if (i.second == maxVal) {
        cout << i.first << " ";
      }
    }
    cout << "\n";
  }
}