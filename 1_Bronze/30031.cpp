#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int sum = 0;
  while (N--) {
    int w, h;
    cin >> w >> h;
    if (w == 136) sum += 1000;
    else if (w == 142) sum += 5000;
    else if (w == 148) sum += 10000;
    else if (w == 154) sum += 50000;
  }
  cout << sum;
}