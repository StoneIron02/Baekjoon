#include <iostream>
#include <regex>
using namespace std;

regex re("[^a-zA-Z-]+");

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string maxStr = "";
  int maxCnt = 0;
  string str;
  while (getline(cin, str)) {
    std::sregex_token_iterator it(str.begin(), str.end(), re, -1);
    std::sregex_token_iterator reg_end;

    for (; it != reg_end; ++it) {
      string token = it->str();
      if (token == "E-N-D") {
        std::transform(maxStr.begin(), maxStr.end(), maxStr.begin(), [](unsigned char c) { return tolower(c); });
        cout << maxStr;
        exit(0);
      }
      if (token.size() > maxCnt) {
        maxCnt = token.size();
        maxStr = token;
      }
    }
  }
}