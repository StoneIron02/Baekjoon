#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string str;
  cin >> str;
  cout << (str[0] == 'E' ? 'I' : 'E');
  cout << (str[1] == 'N' ? 'S' : 'N');
  cout << (str[2] == 'F' ? 'T' : 'F');
  cout << (str[3] == 'P' ? 'J' : 'P');
}
