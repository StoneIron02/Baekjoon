#include <iostream>

using namespace std;
int cnt[3];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  for (int i = 0 ; i < 3; i++) {
    int num;
    cin >> num;
    cnt[num]++;
  }

  if (cnt[1] < cnt[2]) {
    cout << 2;
  } else {
    cout << 1;
  }
}