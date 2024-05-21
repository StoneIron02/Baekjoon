#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

namespace AhoCorasick {
template <typename T> struct node {
  std::unordered_map<T, node *> go;
  node<T> *fail;
  std::vector<size_t> output;

  node() { fail = nullptr; }

  ~node() {
    for (auto &[ch, child] : go) {
      delete child;
    }
  }

  node<T> *find(const T &key) {
    if (go.find(key) != go.end()) {
      return go[key];
    }
    return nullptr;
  }
};

template <typename T>
class AhoCorasick {
private:
  node<T> *root;
  std::vector<std::vector<T>> patterns;

public:
  AhoCorasick() { root = new node<T>(); }
  ~AhoCorasick() { delete root; }

  /**
   * Insert the pattern in Aho-Corasick trie.
   * @param pattern
   * @param representative_pattern representative_pattern of oppm_node
   */
  void insert(const std::vector<T> &pattern, size_t representative_pattern) {
    node<T> *current = root;
    for (const T &ch : pattern) {
      if (!current->find(ch)) {
        current->go[ch] = new node<T>();
      }
      current = current->find(ch);
    }
    current->output.push_back(representative_pattern);
    patterns.push_back(pattern);
  }

  /**
   * Construct the trie with given patterns.
   * @param pattern_set
   */
  void construct(const std::vector<std::vector<T>> &pattern_set) {
    size_t representative_pattern = 0;
    for (const auto &pattern : pattern_set) {
      insert(pattern, representative_pattern);
      ++representative_pattern;
    }
  }

  /**
   * Construct the trie with given patterns for string.
   * @param pattern_set
   */
  void construct(const std::vector<std::string> &pattern_set) {
    size_t representative_pattern = 0;
    for (const auto &pattern : pattern_set) {
      insert(std::vector<char>(pattern.begin(), pattern.end()), representative_pattern);
      ++representative_pattern;
    }
  }

  /**
   * Compute the KMP failure function.
   */
  void build_failure_function() {
    std::queue<node<T> *> que;
    root->fail = root;

    for (const auto &[ch, child] : root->go) {
      que.push(child);
      child->fail = root;
    }

    while (!que.empty()) {
      node<T> *current = que.front();
      que.pop();

      for (const auto &[ch, child] : current->go) {
        node<T> *failure = current->fail;
        while (failure != root && !failure->find(ch)) {
          failure = failure->fail;
        }

        if (failure->find(ch)) {
          failure = failure->find(ch);
        }
        child->fail = failure;

        for (auto &index : child->fail->output) {
          child->output.push_back(index);
        }
        que.push(child);
      }
    }
  }

  /**
   * A searcher that implements the Aho-Corasick algorithm.
   * @param text
   * @return
   */
  std::vector<std::pair<size_t, size_t>> search(const std::vector<T> &text) {
    std::vector<std::pair<size_t, size_t>> result;

    node<T> *current = root;
    for (int i = 0; i < text.size(); ++i) {
      while (current != root && !current->find(text[i])) {
        current = current->fail;
      }

      if (current->find(text[i])) {
        current = current->find(text[i]);
      }

      for (auto &state : current->output) {
        result.emplace_back(i - patterns[state].size() + 1, state);
      }
    }

    return result;
  }

  /**
   * A searcher that implements the Aho-Corasick algorithm for string.
   * @param text
   * @return
   */
  std::vector<std::pair<size_t, size_t>> search(const std::string &text) {
    return search(std::vector<char>(text.begin(), text.end()));
  }

};
} // namespace AhoCorasick

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  AhoCorasick::AhoCorasick<char> ac;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    ac.insert(vector<char>(str.begin(), str.end()), i);
  }
  ac.build_failure_function();

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    string str;
    cin >> str;
    cout << (!ac.search(str).empty() ? "YES\n" : "NO\n");
  }
}