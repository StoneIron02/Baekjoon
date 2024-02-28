#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t = 1;
  int n;
  while (cin >> n) {
    if (n == 0) break;
    cin.ignore();
    string str;
    vector<string> arr;
    for (int i = 0; i < n; i++) {
      getline(cin, str);
      arr.push_back(str);
    }
    sort(arr.begin(), arr.end());
    cout << t++ << "\n";
    for (int i = 0; i < n; i++) {
      cout << arr[i] << "\n";
    }
  }
}