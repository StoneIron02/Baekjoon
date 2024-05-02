#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    string str;
    cin >> str;
    int mid = str.length() / 2;
    cout << ((str[mid - 1] == str[mid]) ? "Do-it\n" : "Do-it-Not\n");
  }
}