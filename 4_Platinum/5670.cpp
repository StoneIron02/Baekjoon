#include <algorithm>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>

using namespace std;

long long sum = 0;

class Trie {
  struct node {
    node* go[26];
    int cnt;
    bool accept;

    node() {
      for (auto& i : go) {
        i = nullptr;
      }
      cnt = 0;
      accept = false;
    }

    ~node() {
      for (auto& i : go) {
        delete i;
      }
    }
  };

public:
  node *root;

  Trie() : root(new node()) {}

  ~Trie() {
    delete root;
  }

  void insert(const string& str) {
    node* curNode = root;
    for (char d : str) {
      if (!curNode->go[d - 'a']) {
        curNode->go[d - 'a'] = new node();
        curNode->cnt++;
      }
      curNode = curNode->go[d - 'a'];
    }
    curNode->accept = true;
  }

  void search(const string& str) {
    int cnt = 0;
    node* curNode = root;
    for (char c : str) {
      if (curNode == root) {
        cnt++;
      }
      else if (curNode->accept) {
        cnt++;
      }
      else if (curNode->cnt >= 2) {
        cnt++;
      }

      curNode = curNode->go[c - 'a'];
    }
    sum += cnt;
  }
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  while (cin >> n) {
    sum = 0;
    Trie trie;
    vector<string> str_set;
    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;
      str_set.push_back(str);
      trie.insert(str);
    }
    for (string& str : str_set) {
      trie.search(str);
    }
    cout << fixed << setprecision(2) << 1.0 * sum / n << "\n";
  }
}