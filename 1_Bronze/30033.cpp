#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  int arr[1000];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int real;
    cin >> real;
    if (real - arr[i] >= 0) cnt++;
  }
  cout << cnt;
}
