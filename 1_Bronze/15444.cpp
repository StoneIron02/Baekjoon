#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, vector<string>> block = {
    {'A', {"***", "*.*", "***", "*.*", "*.*"}},
    {'B', {"***", "*.*", "***", "*.*", "***"}},
    {'C', {"***", "*..", "*..", "*..", "***"}},
    {'D', {"***", "*.*", "*.*", "*.*", "***"}},
    {'E', {"***", "*..", "***", "*..", "***"}}
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  string S;
  cin >> S;

  vector<string> output(5, "");

  for(char c : S) {
    for(int row = 0; row < 5; row++){
      output[row] += block[c][row];
    }
  }

  for(int row = 0; row < 5; row++){
    cout << output[row] << "\n";
  }
}