#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int r, c;
int t;
int arr[40][40];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> arr[i][j];
    }
  }
  cin >> t;

  int cnt = 0;
  for (int i = 0; i < r - 2; i++) {
    for (int j = 0; j < c - 2; j++) {
      vector<int> vec;
      for (int u = 0; u < 3; u++) {
        for (int v = 0; v < 3; v++) {
          vec.push_back(arr[i + u][j + v]);
        }
      }
      sort(vec.begin(), vec.end());
      if (vec[4] >= t) {
        cnt++;
      }
    }
  }
  cout << cnt;
}