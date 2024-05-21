#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<
    int,
    __gnu_pbds::null_type,
    std::less_equal<>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
    > multiset;

typedef __gnu_pbds::tree<
    int,
    int,
    std::less_equal<>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
    > multimap;

/**
 * Construct Prefix Representation.
 * @param str input string
 * @return prefix representation sequence
 */
std::vector<int> compute_prefix_representation(const std::vector<int>& str) {
  std::vector<int> result;
  multiset set;
  for (auto i : str) {
    set.insert(i);
    result.push_back(set.order_of_key(i) + 1);
  }
  return result;
}

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

namespace AhoCorasick {
struct oppm_node {
  std::unordered_map<int, oppm_node *> go;
  oppm_node *fail;
  std::vector<size_t> output;
  size_t depth;
  size_t representative_pattern;

  oppm_node() {
    fail = nullptr;
    depth = 0;
    representative_pattern = 0;
  }
  ~oppm_node() = default;
};

class OPPMAhoCorasick {
private:
  oppm_node *root;
  std::vector<std::vector<int>> patterns;

public:
  OPPMAhoCorasick() {
    root = new oppm_node();
    root->representative_pattern = 0;
    root->depth = 0;
  }
  ~OPPMAhoCorasick() { delete root; }

  /**
   * Insert the pattern in Aho-Corasick trie.
   * @param pattern
   * @param representative_pattern representative pattern of current oppm_node
   */
  void insert(const std::vector<int> &pattern, size_t representative_pattern) {
    oppm_node *current = root;
    std::vector<int> prefix_rep = compute_prefix_representation(pattern);
    size_t idx = 1;
    for (const int &ch : prefix_rep) {
      if (current->go.find(ch) == current->go.end()) {
        current->go[ch] = new oppm_node();
        current->go[ch]->depth = current->depth + 1;
        current->go[ch]->representative_pattern = representative_pattern;
      }
      current = current->go[ch];
      ++idx;
    }
    current->output.push_back(representative_pattern);
    patterns.push_back(pattern);
  }

  /**
   * Construct the trie with given patterns.
   * @param pattern_set
   */
  void construct(const std::vector<std::vector<int>> &pattern_set) {
    size_t state = patterns.size();
    for (const std::vector<int> &pattern : pattern_set) {
      insert(pattern, state);
      ++state;
    }
  }

  /**
   * Compute the KMP failure function.
   */
  void build_failure_function() {
    std::queue<oppm_node *> que;
    root->fail = root;
    std::vector<multimap> T(patterns.size());

    for (const auto &[ch, child] : root->go) {
      que.push(child);
      child->fail = root;
    }

    while (!que.empty()) {
      oppm_node *current = que.front();
      que.pop();

      for (const auto &[ch, child] : current->go) {
        int c = patterns[child->representative_pattern][child->depth - 1];

        // insert node
        if (current->representative_pattern != child->representative_pattern) {
          for (size_t k = 0; k < current->fail->depth; ++k) {
            T[child->representative_pattern].insert(
                {patterns[child->representative_pattern]
                         [current->depth - current->fail->depth + k],
                 current->depth - current->fail->depth + k});
          }
        }
        T[child->representative_pattern].insert({c, child->depth});
        int r = static_cast<int>(T[child->representative_pattern].order_of_key(c + 1));

        // get failure node
        oppm_node *failure = current->fail;
        while (failure->go.find(r) == failure->go.end()) {
          size_t kl = current->depth - failure->depth;
          size_t ku = current->depth - failure->fail->depth - 1;

          for (size_t k = kl; k < ku + 1; ++k) {
            int eraseVal = patterns[child->representative_pattern][k];
            T[child->representative_pattern].erase(
                T[child->representative_pattern].find_by_order(
                    T[child->representative_pattern].order_of_key(eraseVal)));
          }
          r = static_cast<int>(T[child->representative_pattern].order_of_key(c + 1));
          failure = failure->fail;
        }
        child->fail = failure->go[r];

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
  std::vector<std::pair<size_t, size_t>> search(const std::vector<int> &text) {
    std::vector<std::pair<size_t, size_t>> result;

    multimap T;
    oppm_node *current = root;
    for (size_t i = 0; i < text.size(); ++i) {
      T.insert({text[i], i});
      int r = static_cast<int>(T.order_of_key(text[i] + 1));

      while (current->go.find(r) == current->go.end()) {
        size_t depth = current->depth - current->fail->depth;
        size_t kl = i - current->depth;
        size_t ku = i - current->depth + depth;

        for (size_t k = kl; k < ku; k++) {
          T.erase(T.find_by_order(T.order_of_key(text[k])));
        }
        current = current->fail;
        r = static_cast<int>(T.order_of_key(text[i] + 1));
      }

      current = current->go[r];
      for (auto &state : current->output) {
        result.emplace_back(i - patterns[state].size() + 1, state);
        return result; // for this problem
      }
    }

    return result;
  }
};
} // namespace AhoCorasick

int main() {
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int k, m, n;
  std::cin >> k >> m >> n;
  std::vector<int> text(n);
  std::vector<std::vector<int>> patterns(m);
  for (int i = 0; i < m; i++) {
    std::vector<int> v(k);
    for (int j = 0; j < k; j++) {
      std::cin >> v[j];
    }
    patterns[i] = v;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> text[i];
  }

  AhoCorasick::OPPMAhoCorasick ac;
  ac.construct(patterns);
  ac.build_failure_function();
  std::vector<std::pair<size_t, size_t>> result = ac.search(text);
  for (const auto& [s, i] : result) {
    for (const auto& c : patterns[i]) {
      std::cout << c << " ";
    }
  }
  if (result.empty()) {
    std::cout << 0;
  }
}