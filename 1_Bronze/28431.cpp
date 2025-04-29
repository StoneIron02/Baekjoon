#include <iostream>
using namespace std;

int cnt[10];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < 5; i++) {
    int num;
    cin >> num;
    cnt[num]++;
  }
  for (int i = 0; i < 10; i++) {
    if (cnt[i] % 2 == 1) cout << i;
  }
}
