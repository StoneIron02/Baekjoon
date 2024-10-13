#include <iostream>
#include <vector>

using namespace std;

class Trie {
  struct node {
    vector<pair<char, node*>> go;
    int terminalCnt = 0;

    node* find(char c) {
      for (auto& [ch, nextNode] : go) {
        if (ch == c) return nextNode;
      }
      return nullptr;
    }
  };

private:
  node* root;

public:
  Trie() {
    root = new node();
  }

  void insert(string& str) {
    node* curNode = root;
    node* nextNode;
    string res;
    bool print = false;
    for (char c : str) {
      res += c;
      nextNode = curNode->find(c);
      if (nextNode == nullptr) {
        nextNode = new node();
        curNode->go.emplace_back(c, nextNode);
        if (!print) {
          cout << res << "\n";
          print = true;
        }
      }
      curNode = nextNode;
    }
    curNode->terminalCnt++;
    if (!print) {
      if (curNode->terminalCnt > 1) {
        cout << res << curNode->terminalCnt << "\n";
      } else {
        cout << res << "\n";
      }
    }
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
    trie.insert(str);
  }
}