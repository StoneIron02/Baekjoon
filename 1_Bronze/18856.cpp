#include <iostream>
#include <vector>

using namespace std;

bool check(int num) {
  if (num < 2) return false;

  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  cout << N << "\n";

  vector<int> A(N);
  A[0] = 1;
  A[1] = 2;
  for (int i = 2; i < N - 1; i++) {
    A[i] = A[i - 1] + 1;
  }

  int lastNum = A[N - 2] + 1;
  while (!check(lastNum)) {
    lastNum++;
  }
  A[N - 1] = lastNum;

  for (int i = 0; i < N; i++) {
    cout << A[i] << " ";
  }
  cout << "\n";

  return 0;
}