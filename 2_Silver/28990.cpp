#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int& i : arr) {
    cin >> i;
  }

  int sum = 0;
  int oddMinIdx = 0;
  int evenMaxIdx = 1;
  for (int i = 0; i < arr.size(); i += 2) {
    sum += arr[i];
    oddMinIdx = arr[i] < arr[oddMinIdx] ? i : oddMinIdx;
  }
  for (int i = 1; i < arr.size(); i += 2) {
    sum -= arr[i];
    evenMaxIdx = arr[i] > arr[evenMaxIdx] ? i : evenMaxIdx;
  }

  if (arr[oddMinIdx] < arr[evenMaxIdx]) {
    sum += arr[evenMaxIdx] * 2;
    sum -= arr[oddMinIdx] * 2;
  }
  cout << sum;
}
