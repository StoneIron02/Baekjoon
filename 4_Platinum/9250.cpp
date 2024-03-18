#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace AhoCorasick {
const int ALPHABET_SIZE = 26;
struct node {
  node *go[ALPHABET_SIZE]{};
  node *fail;
  vector<int> output;

  node() {
    for (auto &i : go) {
      i = nullptr;
    }
    fail = nullptr;
  }

  ~node() {
    for (auto &i : go) {
      delete i;
    }
  }
};

class AhoCorasick {
private:
  node *root;
  vector<string> patterns;

public:
  AhoCorasick() : root(new node()) {}
  ~AhoCorasick() { delete root; }

  void insertPattern(const string &pattern, int patternIndex) {
    node *current = root;
    for (char ch : pattern) {
      int index = ch - 'a';
      if (!current->go[index]) {
        current->go[index] = new node();
      }
      current = current->go[index];
    }
    current->output.push_back(patternIndex);
    patterns.push_back(pattern);
  }

  void buildFailureFunction() {
    queue<node *> q;
    root->fail = root;
    q.push(root);

    while (!q.empty()) {
      node *current = q.front();
      q.pop();

      for (int i = 0; i < ALPHABET_SIZE; ++i) {
        node *child = current->go[i];
        if (!child) continue;

        if (current == root) {
          child->fail = root;
        } else {
          node *failure = current->fail;

          while (failure != root && !failure->go[i]) {
            failure = failure->fail;
          }

          if (failure->go[i]) {
            failure = failure->go[i];
          }
          child->fail = failure;
        }

        for (auto& index : child->fail->output) {
          child->output.push_back(index);
        }
        q.push(child);
      }
    }
  }

  bool search(const string &text) {
    node *current = root;

    for (int i = 0; i < text.length(); ++i) {
      int index = text[i] - 'a';

      while (current != root && !current->go[index]) {
        current = current->fail;
      }

      if (current->go[index]) {
        current = current->go[index];
      }

      if (!current->output.empty()) {
        return true;
      }
    }
    return false;
  }
};
} // namespace AhoCorasick

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  AhoCorasick::AhoCorasick ac;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    ac.insertPattern(str, i);
  }
  ac.buildFailureFunction();

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    string str;
    cin >> str;
    cout << (ac.search(str) ? "YES\n" : "NO\n");
  }
}