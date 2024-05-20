#include <iostream>
#include <regex>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string text;
  while (getline(cin, text)) {
    int pos;
    while ((pos = text.find("BUG")) != string::npos) {
      text.replace(pos, 3, "");
    }
    cout << text << "\n";
  }

}