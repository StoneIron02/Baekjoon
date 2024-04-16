#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct node {
  node* next[26];
  int count;

  node() {
    for (auto& i : next) {
      i = nullptr;
    }
    count = 0;
  }
};

class Trie {
public:
  node* root;

  Trie() {
    root = new node();
  }

  void insert(const string& str) {
    node* curNode = root;
    for (char c : str) {
      if (!curNode->next[c - 'a']) {
        curNode->next[c - 'a'] = new node();
      }
      curNode = curNode->next[c - 'a'];
      curNode->count++;
    }
  }

  void remove(const string& str) {
    node* curNode = root;
    for (char c : str) {
      curNode = curNode->next[c - 'a'];
      curNode->count--;
    }
  }
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int q;
  cin >> q;
  Trie t1;
  Trie t2;
  while (q--) {
    string cmd;
    cin >> cmd;
    if (cmd == "add") {
      string type;
      cin >> type;
      if (type == "A") {
        string str;
        cin >> str;
        t1.insert(str);
      } else if (type == "B") {
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        t2.insert(str);
      }
    } else if (cmd == "delete") {
      string type;
      cin >> type;
      if (type == "A") {
        string str;
        cin >> str;
        t1.remove(str);
      } else if (type == "B") {
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        t2.remove(str);
      }
    } else if (cmd == "find") {
      string str;
      cin >> str;
      node* curNode1 = t1.root;
      node* curNode2 = t2.root;
      vector<int> cnt1(str.size(), 0);
      vector<int> cnt2(str.size(), 0);

      for (int i = 0; i < str.size(); i++) {
        if (!curNode1->next[str[i] - 'a']) {
          break;
        }
        curNode1 = curNode1->next[str[i] - 'a'];
        cnt1[i] = curNode1->count;
      }

      for (int i = str.size() - 1; i > 0; i--) {
        if (!curNode2->next[str[i] - 'a']) {
          break;
        }
        curNode2 = curNode2->next[str[i] - 'a'];
        cnt2[i - 1] = curNode2->count;
      }

      long long sum = 0;
      for (int i = 0; i < str.size(); i++) {
        sum += cnt1[i] * cnt2[i];
      }
      cout << sum << "\n";
    }
  }
}