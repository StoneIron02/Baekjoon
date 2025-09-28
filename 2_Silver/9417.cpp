#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  cin.ignore();
  while (N--) {
    string str;
    getline(cin, str);
    stringstream ss(str);

    int num;
    vector<int> arr;
    while (ss >> num) {
      arr.push_back(num);
    }

    int max_g = 0;
    for (int i = 0; i < arr.size(); ++i) {
      for (int j = i + 1; j < arr.size(); ++j) {
        int g = gcd(arr[i], arr[j]);
        max_g = max(max_g, g);
      }
    }

    cout << max_g << "\n";
  }
}