#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int num = 1;
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cout << num++;
    for (int j = 1; j < M; j++) {
      cout << " " << num++;
    }
    cout << "\n";
  }
}