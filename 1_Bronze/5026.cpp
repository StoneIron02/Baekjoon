#include <iostream>
#include <sstream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  cin.ignore();
  while (n--) {
    string str;
    getline(cin, str);
    if (str == "P=NP") {
      cout << "skipped\n";
      continue;
    }

    stringstream ss(str);
    int a, b;
    string aStr, bStr;
    getline(ss, aStr, '+');
    getline(ss, bStr);
    a = stoi(aStr);
    b = stoi(bStr);
    cout << a + b << "\n";
  }
}