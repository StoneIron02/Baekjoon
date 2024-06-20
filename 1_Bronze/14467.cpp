#include <iostream>
using namespace std;

bool flag[11];
int location[11];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int cnt = 0;
  while (n--) {
    int num, loc;
    cin >> num >> loc;
    if (!flag[num]) {
      flag[num] = true;
      location[num] = loc;
    } else {
      if (location[num] != loc) {
        cnt++;
      }
      location[num] = loc;
    }
  }
  cout << cnt;
}