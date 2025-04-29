#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, char> mp = {
  {' ', ' '},
  {'1', '`'},
  {'2', '1'},
  {'3', '2'},
  {'4', '3'},
  {'5', '4'},
  {'6', '5'},
  {'7', '6'},
  {'8', '7'},
  {'9', '8'},
  {'0', '9'},
  {'-', '0'},
  {'=', '-'},
  {'W', 'Q'},
  {'E', 'W'},
  {'R', 'E'},
  {'T', 'R'},
  {'Y', 'T'},
  {'U', 'Y'},
  {'I', 'U'},
  {'O', 'I'},
  {'P', 'O'},
  {'[', 'P'},
  {']', '['},
  {'\\', ']'},
  {'S', 'A'},
  {'D', 'S'},
  {'F', 'D'},
  {'G', 'F'},
  {'H', 'G'},
  {'J', 'H'},
  {'K', 'J'},
  {'L', 'K'},
  {';', 'L'},
  {'\'', ';'},
  {'X', 'Z'},
  {'C', 'X'},
  {'V', 'C'},
  {'B', 'V'},
  {'N', 'B'},
  {'M', 'N'},
  {',', 'M'},
  {'.', ','},
  {'/', '.'},
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  while (getline(cin, str)) {
    for (char c : str) {
      cout << mp[c];
    }
  cout << "\n";
  }
}
