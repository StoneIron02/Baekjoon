#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> arr(10, vector<char>(20, '.'));

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    int row = str[0] - 'A';
    int col = stoi(str.substr(1)) - 1;
    arr[row][col] = 'o';
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      cout << arr[i][j];
    }
    cout << "\n";
  }
}
