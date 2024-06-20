#include <iostream>
using namespace std;

string arr[50];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int r, c, zr, zc;
  cin >> r >> c >> zr >> zc;
  for (int i = 0; i < r; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < r; i++) {
    for (int h = 0; h < zr; h++) {
      for (int j = 0; j < c; j++) {
        char ch = arr[i][j];
        for (int k = 0; k < zc; k++) {
          cout << ch;
        }
      }
      cout << "\n";
    }
  }
}