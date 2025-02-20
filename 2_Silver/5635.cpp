#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
  string name;
  int day{}, month{}, year{};
};

bool isYounger(const Student &a, const Student &b) {
  if (a.year != b.year) return a.year > b.year;
  if (a.month != b.month) return a.month > b.month;
  return a.day > b.day;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<Student> students(n);

  for (int i = 0; i < n; i++) {
    cin >> students[i].name >> students[i].day >> students[i].month >> students[i].year;
  }

  sort(students.begin(), students.end(), isYounger);

  cout << students[0].name << "\n";
  cout << students[n - 1].name << "\n";

  return 0;
}
