#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, count = 0;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string S;
    cin >> S;
    if (S.find("01") != string::npos || S.find("OI") != string::npos) {
      ++count;
    }
  }
  cout << count << endl;
}
