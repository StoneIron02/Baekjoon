#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  int i = 2;
  while (true) {
    getline(cin, str);
    if (str == "Was it a cat I saw?") break;

    for (int j = 0; j < str.size(); j += i) {
      cout << str[j];
    }
    cout << "\n";

    i++;
  }
}