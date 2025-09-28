#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> A[100'000];
int B[100'000];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    A[i] = make_pair(num, i);
  }

  sort(A, A + N);
  for (int i = 0; i < N; ++i) {
    B[A[i].second] = A[N - 1 - i].first;
  }
  for (int i = 0; i < N; ++i) {
    cout << B[i] << " ";
  }
}