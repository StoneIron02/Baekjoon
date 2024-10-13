#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str1, str2, str3;
  while (true) {
    cin >> str1;
    if (str1 == "#") break;
    cin >> str2 >> str3;
    int val[20];
    for (int i = 0; i < str1.size(); i++) {
      val[i] = (str2[i] - str1[i] + 26) % 26;
    }
    cout << str1 << " " << str2 << " " << str3 << " ";
    for (int i = 0; i < str1.size(); i++) {
      char c = (char)((str3[i] - 'a' + val[i]) % 26 + 'a');
      cout << c;
    }
    cout << "\n";
  }
}