#include <iostream>
#include <vector>

using namespace std;

class Trie {
  struct node {
    node* go[26];

    ~node() {
      for (auto& i : go) {
        delete i;
      }
    }
  };

private:
  node* root;

public:
  Trie() {
    root = new node();
  }

  ~Trie() {
    delete root;
  }

  void insert(const string& str) {
    node* curNode = root;
    for (char c : str) {
      if (!curNode->go[c - 'a']) {
        curNode->go[c - 'a'] = new node();
      }
      curNode = curNode->go[c - 'a'];
    }
  }

  bool find(const string& str) {
    node* curNode = root;
    for (char c : str) {
      if (!curNode->go[c - 'a']) {
        return false;
      } else {
        curNode = curNode->go[c - 'a'];
      }
    }
    return true;
  }
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  Trie trie;
  while (n--) {
    string str;
    cin >> str;
    trie.insert(str);
  }

  int cnt = 0;
  while (m--) {
    string str;
    cin >> str;
    if (trie.find(str)) {
      cnt++;
    }
  }
  cout << cnt;
}