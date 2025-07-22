#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  string S;
  cin >> N >> S;

  if (S.find("gori") != string::npos) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}