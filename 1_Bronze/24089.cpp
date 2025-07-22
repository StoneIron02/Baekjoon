#include <iostream>

using namespace std;

int box[2001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    box[i] = i;
  }
  while (M--) {
    int x, y;
    cin >> x >> y;
    box[x] = y;
  }
  for (int i = 1; i <= N; i++) {
    cout << box[i] << "\n";
  }
}