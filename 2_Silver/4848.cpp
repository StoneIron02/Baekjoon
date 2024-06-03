#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> sToi;
string iTos[16];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  iTos[0] = "{}";
  sToi["{}"] = 0;
  for (int i = 1; i <= 15; i++) {
    string str = "{";
    for (int j = 0; j < i - 1; j++) {
      str += iTos[j];
      str += ",";
    }
    str += iTos[i - 1];
    str += "}";
    iTos[i] = str;
    sToi[str] = i;
  }

  int n;
  cin >> n;
  while (n--) {
    string str1, str2;
    cin >> str1 >> str2;
    int num1, num2;
    num1 = sToi[str1];
    num2 = sToi[str2];
    int res = num1 + num2;
    cout << iTos[res] << "\n";
  }
}