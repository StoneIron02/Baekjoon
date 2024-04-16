#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<string> names;

class Trie {
  struct node {
    node* go[26]{};
    bool accept;

    node() {
      for (auto & i : go) {
        i = nullptr;
      }
      accept = false;
    }
  };

private:
  node *root;

public:
  Trie() : root(new node()) {}

  void insert(const string& str) {
    node* curNode = root;
    for (char d : str) {
      if (!curNode->go[d - 'a']) {
        curNode->go[d - 'a'] = new node();
      }
      curNode = curNode->go[d - 'a'];
    }
    curNode->accept = true;
  }

  bool search(const string& str) {
    node* curNode = root;
    for (int i = 0; i < str.size(); i++) {
      char d = str[i];
      if (!curNode->go[d - 'a']) {
        return false;
      }
      curNode = curNode->go[d - 'a'];
      if (curNode->accept) {
        if (names.find(str.substr(i + 1)) != names.end()) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  Trie colors = Trie();

  int c, n;
  cin >> c >> n;
  while (c--) {
    string str;
    cin >> str;
    colors.insert(str);
  }
  while (n--) {
    string str;
    cin >> str;
    names.insert(str);
  }
  int q;
  cin >> q;
  while (q--) {
    string str;
    cin >> str;
    cout << (colors.search(str) ? "Yes" : "No") << "\n";
  }
}