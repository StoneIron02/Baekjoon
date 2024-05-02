#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;

char board[4][4];
bool visit[4][4];

unordered_set<string> found;

class Trie {
  struct node {
    vector<pair<char, node*>> go;
    bool accept = false;
    string str;

    int find(char c) {
      for (int i = 0; i < go.size(); i++) {
        if (go[i].first == c) {
          return i;
        }
      }
      return -1;
    }
  };

private:
  string dx = "02110022";
  string dy = "11020202";

public:
  node* root;

  Trie() {
    root = new node();
  }

  void insert(const string& str) {
    node* curNode = root;
    for (char c : str) {
      int f = curNode->find(c);
      if (f == -1) {
        curNode->go.emplace_back(c, new node());
        curNode = curNode->go.back().second;
      } else {
        curNode = curNode->go[f].second;
      }
    }
    curNode->accept = true;
    curNode->str = str;
  }

  void DFS(node* curNode, int i, int j) {
    if (curNode->accept) {
      found.insert(curNode->str);
      return;
    }

    for (int k = 0; k < dx.size(); k++) {
      int x = i + (dx[k] - '1');
      int y = j + (dy[k] - '1');

      if (x < 0 || x >= 4)
        continue;
      if (y < 0 || y >= 4)
        continue;
      if (visit[x][y])
        continue;

      for (auto& [c, g] : curNode->go) {
        if (c == board[x][y]) {
          visit[x][y] = true;
          DFS(g, x, y);
          visit[x][y] = false;
        }
      }
    }
  }
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int w;
  cin >> w;
  Trie trie;
  for (int i = 0; i < w; i++) {
    string str;
    cin >> str;
    trie.insert(str);
  }

  int b;
  cin >> b;
  while (b--) {
    found.clear();
    vector<pii> first;

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cin >> board[i][j];
        visit[i][j] = false;
        if (trie.root->find(board[i][j]) != -1) {
          first.emplace_back(i, j);
        }
      }
    }

    for (auto& [i, j] : first) {
      visit[i][j] = true;
      trie.DFS(trie.root->go[trie.root->find(board[i][j])].second, i, j);
      visit[i][j] = false;
    }

    int totScore = 0;
    string maxStr;
    int wordCnt = 0;
    for (auto& str : found) {
      int len = str.length();
      if (len == 3 || len == 4) totScore += 1;
      else if (len == 5) totScore += 2;
      else if (len == 6) totScore += 3;
      else if (len == 7) totScore += 5;
      else if (len == 8) totScore += 11;

      if (len > maxStr.length()) {
        maxStr = str;
      }
      if (len == maxStr.length()) {
        maxStr = str < maxStr ? str : maxStr;
      }

      wordCnt++;
    }

    cout << totScore << " " << maxStr << " " << wordCnt << "\n";
  }

}