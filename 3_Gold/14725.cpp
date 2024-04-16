#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Trie {
  struct node {
    map<string, node*> next;
    bool accept = false;
  };

private:
  node* root;

public:
  Trie() {
    root = new node();
  }

  void insert(const vector<string>& str_set) {
    node* curNode = root;
    for (const string& str : str_set) {
      if (curNode->next.find(str) == curNode->next.end()) {
        curNode->next[str] = new node();
      }
      curNode = curNode->next[str];
    }
    curNode->accept = true;
  }

  void order(node* curNode, int step) {
    for (auto& [str, next] : curNode->next) {
      for (int i = 0; i < step; i++) {
        cout << "--";
      }
      cout << str << "\n";
      order(next, step + 1);
    }
  }

  void order() {
    order(root, 0);
  }
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  Trie trie;
  while (n--) {
    int k;
    cin >> k;
    vector<string> s;
    while (k--) {
      string str;
      cin >> str;
      s.push_back(str);
    }
    trie.insert(s);
  }
  trie.order();
}