#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  cin.ignore();

  for (int i = 1; i <= N; ++i) {
    string str;
    getline(cin, str);

    istringstream iss(str);
    vector<string> words;
    string word;

    while (iss >> word) {
      words.push_back(word);
    }

    reverse(words.begin(), words.end());

    cout << "Case #" << i << ":";
    for (const auto& w : words) {
      cout << " " << w;
    }
    cout << '\n';
  }
}