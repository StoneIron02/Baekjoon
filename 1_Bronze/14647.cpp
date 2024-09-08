#include <iostream>

using namespace std;

int n, m;
int arr[500][500];
int sumRow[500];
int sumCol[500];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      string num;
      cin >> num;
      int cnt = 0;
      for (char c : num) {
        if (c == '9') {
          cnt++;
        }
      }
      arr[i][j] = cnt;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sumRow[i] += arr[i][j];
      sumCol[j] += arr[i][j];
    }
  }

  bool isRow = true;
  int maxIdx = 0;
  int maxVal = sumRow[0];
  for (int i = 0; i < n; i++) {
    if (maxVal < sumRow[i]) {
      maxIdx = i;
      maxVal = sumRow[i];
    }
  }
  for (int j = 0; j < m; j++) {
    if (maxVal < sumCol[j]) {
      isRow = false;
      maxIdx = j;
      maxVal = sumCol[j];
    }
  }

  if (isRow) {
    for (int j = 0; j < m; j++) {
      arr[maxIdx][j] = 0;
    }
  } else {
    for (int i = 0; i < n; i++) {
      arr[i][maxIdx] = 0;
    }
  }

  int total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      total += arr[i][j];
    }
  }
  cout << total;
}