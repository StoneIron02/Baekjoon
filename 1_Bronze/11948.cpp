#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int arr[6];
  for (int i = 0; i < 6; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + 4);
  sort(arr + 4, arr + 6);
  cout << arr[1] + arr[2] + arr[3] + arr[5];
}