#include <iostream>
using namespace std;

namespace trie {
struct node {
  node* next[10] {};
  bool isEndChar;

  node() : isEndChar(false) {
  }

  ~node() {
    for (auto& i : next) {
      delete i;
    }
  }
};

class Trie {
private:
  node* root;

  void _insert(node* curNode, const string& value, size_t idx) {
    size_t insertIdx = value[idx] - '0';
    if (curNode->next[insertIdx] == nullptr) {
      curNode->next[insertIdx] = new node();
    }
    if (idx == value.size() - 1) {
      curNode->next[insertIdx]->isEndChar = true;
      return;
    }
    _insert(curNode->next[insertIdx], value, idx + 1);
  }

  bool _isDuplicate(node* curNode) {
    bool result = false;
    for (int i = 0; i < 10; i++) {
      if (curNode->next[i] == nullptr)
        continue;

      if (curNode->isEndChar) {
        return true;
      }
      result = result || _isDuplicate(curNode->next[i]);
    }
    return result;
  }

public:
  Trie() : root(new node()) {
  }

  ~Trie() {
    delete root;
  }

  void insert(const string& value) {
    _insert(root, value, 0);
  }

  bool isDuplicate() {
    return _isDuplicate(root);
  }
};
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    trie::Trie trie;
    for (int i = 0; i < n; i++) {
      string number;
      cin >> number;
      trie.insert(number);
    }
    if (!trie.isDuplicate()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}