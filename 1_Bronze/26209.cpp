#include <iostream>
using namespace std;

int main () {
  for (int i = 0; i < 8; i++) {
    int num;
    cin >> num;
    if (num == 9) {
      cout << "F";
      exit(0);
    }
  }
  cout << "S";
}