#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  int arr[5] {0, 0, 0, 0, 0};
  for (int i = 0; i < t; i++) {
    cin >> arr[i];
  }

  int num1, num2, num3;
  num1 = arr[0] > arr[2] ? (arr[0] - arr[2]) * 508 : (arr[2] - arr[0]) * 108;
  num2 = arr[1] > arr[3] ? (arr[1] - arr[3]) * 212 : (arr[3] - arr[1]) * 305;
  num3 = arr[4] * 707;
  cout << (num1 + num2 + num3) * 4763;
}