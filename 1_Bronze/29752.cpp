#include <iostream>
using namespace std;

int maxCnt = 0;
int cnt = 0;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    if (num == 0) {
      maxCnt = max(maxCnt, cnt);
      cnt = 0;
    } else {
      cnt++;
    }
  }
  maxCnt = max(maxCnt, cnt);
  cout << maxCnt;
}