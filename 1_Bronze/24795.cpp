#include <iostream>
using namespace std;

bool found[101];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, Y;
  cin >> N >> Y;
  for (int i = 0; i < Y; ++i) {
    int k;
    cin >> k;
    found[k] = true;
  }

  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (!found[i]) cout << i << "\n";
    else ++cnt;
  }

  cout << "Mario got " << cnt << " of the dangerous obstacles.";
}