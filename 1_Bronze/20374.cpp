#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string line;
  long long total = 0;

  while (getline(cin, line)) {
    size_t dot_pos = line.find('.');
    string euros = line.substr(0, dot_pos);
    string cents = line.substr(dot_pos + 1);

    long long amount = stoll(euros) * 100 + stoll(cents);
    total += amount;
  }

  long long euros = total / 100;
  long long cents = total % 100;
  cout << euros << '.' << setw(2) << setfill('0') << cents << '\n';
}