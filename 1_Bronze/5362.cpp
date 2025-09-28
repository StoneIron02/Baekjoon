#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string str;
  while (getline(cin, str)) {
    size_t pos = 0;
    while ((pos = str.find("iiing", pos)) != string::npos) {
      str.replace(pos, 5, "th");
      pos += 2;
    }
    cout << str << '\n';
  }
}