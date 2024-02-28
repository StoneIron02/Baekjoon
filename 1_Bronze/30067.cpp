#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int arr[10];
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  for (int i = 0; i < 10; i++) {
    int s = sum - arr[i];
    if (arr[i] == s) {
      cout << s;
      break;
    }
  }
}