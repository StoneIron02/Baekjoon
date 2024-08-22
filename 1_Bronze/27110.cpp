#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  int A, B, C;
  cin >> A >> B >> C;
  int sum = 0;
  sum += min(N, A);
  sum += min(N, B);
  sum += min(N, C);
  cout << sum;
}
