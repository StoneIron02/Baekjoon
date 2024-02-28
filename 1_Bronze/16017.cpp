#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int arr[4];
  for (int i = 0; i < 4; i++) {
    cin >> arr[i];
  }

  if (arr[0] == 8 || arr[0] == 9) {
    if (arr[3] == 8 || arr[3] == 9) {
      if (arr[1] == arr[2]) {
        cout << "ignore";
        exit(0);
      }
    }
  }
  cout << "answer";
}