#include <iostream>

using namespace std;

bool isCppStyle(const string &s) {
  if (s.empty() || s.front() == '_' || s.back() == '_') return false;
  bool hasUnderscore = false;

  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == '_') {
      if (hasUnderscore) return false;
      hasUnderscore = true;
    } else {
      if (!islower(s[i])) return false;
      hasUnderscore = false;
    }
  }
  return true;
}

bool isJavaStyle(const string &s) {
  if (s.empty() || isupper(s[0])) return false;
  for (char c : s) {
    if (c == '_') return false;
  }
  return true;
}

string convertCppToJava(const string &s) {
  string result;
  bool toUpper = false;

  for (char c : s) {
    if (c == '_') {
      toUpper = true;
    } else {
      result += (toUpper ? toupper(c) : c);
      toUpper = false;
    }
  }
  return result;
}

string convertJavaToCpp(const string &s) {
  string result;

  for (char c : s) {
    if (isupper(c)) {
      result += '_';
      result += tolower(c);
    } else {
      result += c;
    }
  }
  return result;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string input;
  cin >> input;

  if (isCppStyle(input)) {
    cout << convertCppToJava(input) << "\n";
  } else if (isJavaStyle(input)) {
    cout << convertJavaToCpp(input) << "\n";
  } else {
    cout << "Error!\n";
  }
}