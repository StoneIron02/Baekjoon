#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str1, str2;
  cin >> str1 >> str2;
  int t1 = stoi(str1.substr(0, 2)) * 3600 + stoi(str1.substr(3, 2)) * 60 + stoi(str1.substr(6, 2));
  int t2 = stoi(str2.substr(0, 2)) * 3600 + stoi(str2.substr(3, 2)) * 60 + stoi(str2.substr(6, 2));
  int diff = t2 - t1;
  if (diff <= 0) {
    diff += 24 * 60 * 60;
  }
  cout << setw(2) << setfill('0') << (diff / 3600) << ":" << setw(2) << ((diff % 3600) / 60) << ":" << setw(2) << ((diff % 3600) % 60);
}