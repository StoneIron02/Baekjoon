#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

int len[5000];
bool flag[300'000];

namespace AhoCorasick {
struct node {
  vector<pair<char, node*>> go;
  node *fail;
  int output;

  explicit node() {
    fail = nullptr;
    output = -1;
  }

  ~node() {
    for (auto& i : go) {
      delete i.second;
    }
  }

  node* find(char c) {
    for (auto& [ch, child] : go) {
      if (ch == c) {
        return child;
      }
    }
    return nullptr;
  }
};

class AhoCorasick {
private:
  node *root;

public:
  AhoCorasick() { root = new node(); }
  ~AhoCorasick() { delete root; }

  void insert(const std::string & pattern, int state) {
    node *current = root;
    for (char ch : pattern) {
      if (!current->find(ch)) {
        current->go.emplace_back(ch, new node());
      }
      current = current->find(ch);
    }
    current->output = state;
    len[state] = pattern.length();
  }

  void build_failure_function() {
    std::queue<node *> que;
    root->fail = root;
    que.push(root);

    while (!que.empty()) {
      node *current = que.front();
      que.pop();

      for (auto& [ch, child] : current->go) {
        if (current == root) {
          child->fail = root;
        } else {
          node *failure = current->fail;

          while (failure != root && !failure->find(ch)) {
            failure = failure->fail;
          }

          if (failure->find(ch)) {
            failure = failure->find(ch);
          }
          child->fail = failure;
        }

        if (child->fail->output != -1) {
          if (child->output == -1) {
            child->output = child->fail->output;
          } else {
            child->output = len[child->output] > len[child->fail->output] ? child->output : child->fail->output;
          }
        }
        que.push(child);
      }
    }
  }

  void search(const std::string &text) {
    node *current = root;
    for (int i = 0; i < text.length(); ++i) {
      char ch = text[i];

      while (current != root && !current->find(ch)) {
        current = current->fail;
      }

      if (current->find(ch)) {
        current = current->find(ch);
      }

      if (current->output != -1) {
        fill(flag + i - len[current->output] + 1, flag + i + 1, true);
      }
    }
  }

};
} // namespace AhoCorasick

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  string text;
  cin >> text;

  AhoCorasick::AhoCorasick ac;

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string str;
    cin >> str;
    ac.insert(str, i);
  }
  ac.build_failure_function();
  ac.search(text);

  int cnt = 0;
  for (int i = 0; i < text.size(); i++) {
    if (!flag[i]) cnt++;
  }
  cout << cnt;
}