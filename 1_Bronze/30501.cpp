#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  while (N--) {
    string str;
    cin >> str;
    if (str.find('S') != string::npos) {
      cout << str;
      exit(0);
    }
  }
}
