#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Trie {
  struct node {
    map<string, node*> go;

    ~node() {
      for (auto& i : go) {
        delete i.second;
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

  void insert(const vector<string>& vec) {
    node* curNode = root;
    for (const string& str : vec) {
      if (!curNode->go[str]) {
        curNode->go[str] = new node();
      }
      curNode = curNode->go[str];
    }
  }

  void trav(node* curNode, int depth) {
    for (auto& [a, b] : curNode->go) {
      for (int i = 0; i < depth + 1; i++) {
        cout << " ";
      }
      cout << a << "\n";
      trav(b, depth + 1);
    }
  }

  void trav() {
    trav(root, -1);
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
    string str;
    cin >> str;
    stringstream ss(str);
    string sub;
    vector<string> vec;

    while(getline(ss,sub,'\\')){
      vec.push_back(sub);
    }

    trie.insert(vec);
  }

  trie.trav();
}