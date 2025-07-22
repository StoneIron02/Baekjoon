#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  string str;
  cin >> N >> str;

  int cnt_bigdata = 0;
  int cnt_security = 0;

  for (size_t i = 0; i < str.length();) {
    if (str[i] == 'b' &&
        str[i + 1] == 'i' &&
        str[i + 2] == 'g' &&
        str[i + 3] == 'd' &&
        str[i + 4] == 'a' &&
        str[i + 5] == 't' &&
        str[i + 6] == 'a') {
      cnt_bigdata++;
      i += 7;
    } else if (str[i] == 's' &&
               str[i + 1] == 'e' &&
               str[i + 2] == 'c' &&
               str[i + 3] == 'u' &&
               str[i + 4] == 'r' &&
               str[i + 5] == 'i' &&
               str[i + 6] == 't' &&
               str[i + 7] == 'y') {
      cnt_security++;
      i += 8;
    }
  }

  if (cnt_bigdata > cnt_security) {
    cout << "bigdata?" << endl;
  } else if (cnt_bigdata < cnt_security) {
    cout << "security!" << endl;
  } else {
    cout << "bigdata? security!" << endl;
  }
}