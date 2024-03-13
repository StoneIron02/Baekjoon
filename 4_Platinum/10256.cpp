#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int result = 0;

namespace AhoCorasick {
const int ALPHABET_SIZE = 4;
unordered_map<char, int> ALPHABET_INDEX = {
    {'A', 0},
    {'C', 1},
    {'G', 2},
    {'T', 3}
};
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
      int index = ALPHABET_INDEX[ch];
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

  void search(const string &text) {
    node *current = root;

    for (int i = 0; i < text.length(); ++i) {
      int index = ALPHABET_INDEX[text[i]];

      while (current != root && !current->go[index]) {
        current = current->fail;
      }

      if (current->go[index]) {
        current = current->go[index];
      }

      for (auto& idx : current->output) {
        result++;
      }
    }
  }
};
} // namespace AhoCorasick

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string text;
    cin >> text;
    string pattern;
    cin >> pattern;
    AhoCorasick::AhoCorasick ac;
    result = 0;

    unordered_set<string> patterns;
    patterns.insert(pattern);
    for (int i = 0; i < m - 1; i++) {
      for (int j = i + 1; j <= m; j++) {
        // 0~i-1, i~j-1, j~m-1
        string p1 = pattern.substr(0, i);
        string p2 = pattern.substr(i, j - i);
        reverse(p2.begin(), p2.end());
        string p3;
        if (j == m) {
          p3 = "";
        } else {
          p3 = pattern.substr(j);
        }
        string p;
        p.append(p1).append(p2).append(p3);
        patterns.insert(p);
      }
    }
    int q = 0;
    for (auto& p : patterns) {
      ac.insertPattern(p, q++);
    }
    ac.buildFailureFunction();
    ac.search(text);
    cout << result << "\n";
  }
}