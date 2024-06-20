#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string str;
    getline(cin, str);
    istringstream sso(str);
    string w;
    deque<string> words;
    while (getline(sso, w, ' ')) {
      words.push_back(w);
    }

    string wordStr;
    while (getline(cin, wordStr)) {
      if (wordStr == "what does the fox say?") {
        break;
      }
      istringstream ss(wordStr);
      string word;
      getline(ss, word, ' ');
      getline(ss, word, ' ');
      getline(ss, word);
      for (int i = words.size() - 1; i >= 0; i--) {
        if (words[i] == word) {
          words.erase(words.begin() + i);
        }
      }
    }

    for (auto st : words) {
      cout << st << " ";
    }
    cout << "\n";
  }
}