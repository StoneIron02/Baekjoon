#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  A--;
  string rev = S.substr(A, B - A);
  reverse(rev.begin(), rev.end());
  cout << S.substr(0, A) + rev + S.substr(B);
}