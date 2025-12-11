#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int J, N;
  cin >> J >> N;
  cin.ignore();

  int cnt = 0;
  while (N--) {
    string str;
    getline(cin, str);
    int sum = 0;
    for (char c : str) {
      if (c == ' ') sum += 1;
      else if (c >= 'A' && c <= 'Z') sum += 4;
      else if (c >= '0' && c <= '9') sum += 2;
      else sum += 2;
    }
    if (sum <= J) ++cnt;
  }

  cout << cnt;
}
