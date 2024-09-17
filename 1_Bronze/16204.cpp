#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M, K;
  cin >> N >> M >> K;
  cout << N - abs(M - K);
}