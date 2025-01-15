#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str = "ABCBCDCDADAB";

  int Z;
  cin >> Z;
  while (Z--) {
    long long N;
    cin >> N;
    cout << str[(N - 1) % 12] << "\n";
  }

}