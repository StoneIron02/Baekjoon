#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, L;
  cin >> N >> L;

  int maxStripes = 0;
  int cntMax = 0;

  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    int cnt = 0;
    bool cur_status = false;
    for (char c : str) {
      if (c == '1') {
        if (!cur_status) {
          cnt++;
          cur_status = true;
        }
      } else {
        cur_status = false;
      }
    }

    if (cnt > maxStripes) {
      maxStripes = cnt;
      cntMax = 1;
    } else if (cnt == maxStripes) {
      cntMax++;
    }
  }

  cout << maxStripes << " " << cntMax;
}
