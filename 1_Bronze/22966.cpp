#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int minVal = 999999999;
  string minName = "";

  for (int i = 0; i < n; i++) {
    int val;
    string name;
    cin >> name >> val;
    if (val < minVal) {
      minVal = val;
      minName = name;
    }
  }
  cout << minName;

}