#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    int num;
    cin >> num;
    if (num != i) cnt++;
  }
  cout << cnt;
}