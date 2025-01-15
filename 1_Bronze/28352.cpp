#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  long long val = 1;
  for (int i = 1; i <= N; i++) {
    val *= i;
  }
  val /= 7 * 24 * 60 * 60;
  cout << val;
}