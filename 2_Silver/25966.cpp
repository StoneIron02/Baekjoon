#include <iostream>
using namespace std;

int n, m, q;
int arr[3000][3000];
int row[3000];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
    row[i] = i;
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 0) {
      int i, j, k;
      cin >> i >> j >> k;
      arr[row[i]][j] = k;
    } else {
      int i, j;
      cin >> i >> j;
      swap(row[i], row[j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << arr[row[i]][j] << " ";
    }
    cout << "\n";
  }
}