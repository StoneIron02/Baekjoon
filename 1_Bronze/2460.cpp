#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int cnt = 0;
  int maxCnt = 0;
  for (int i = 0; i < 10; i++) {
    int n1, n2;
    cin >> n1 >> n2;
    cnt -= n1;
    cnt += n2;
    maxCnt = max(maxCnt, cnt);
  }
  cout << maxCnt;
}