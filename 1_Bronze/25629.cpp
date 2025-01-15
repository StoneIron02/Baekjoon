#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int cntOdd = 0, cntEven = 0;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    if (num % 2 == 1) cntOdd++;
    else cntEven++;
  }
  if ((N % 2 == 1 && cntOdd == N / 2 + 1 && cntEven == N / 2) ||
      N % 2 == 0 && cntOdd == N / 2 && cntEven == N / 2) {
    cout << 1;
  } else {
    cout << 0;
  }
}