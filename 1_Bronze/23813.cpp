#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  long long sum = 0;
  for (int i = 0; i < str.size(); i++) {
    str = str.substr(1) + str[0];
    sum += stoll(str);
  }
  cout << sum;
}