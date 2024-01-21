#include <iostream>
#include <cmath>
using namespace std;

char arr[100][100];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int sz = sqrt(str.size());

    int p = 0;
    for (int j = 0; j < sz; j++) {
      for (int i = sz - 1; i >= 0; i--) {
        arr[i][j] = str[p++];
      }
    }
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        cout << arr[i][j];
      }
    }
    cout << "\n";
  }
}