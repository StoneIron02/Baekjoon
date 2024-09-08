#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  char c;
  cin >> c;
  if (c == 'N' || c == 'n') {
    cout << "Naver D2";
  } else {
    cout << "Naver Whale";
  }
}