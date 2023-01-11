#include <iostream>
#include <string>
using namespace std;

int main() {
	int* arr = new int[26];
	for (int i = 0; i < 26; i++)
		arr[i] = 0;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] - 'a' < 0)
			arr[str[i] - 'A']++;
		else
			arr[str[i] - 'a']++;
	}

	int maxIndex = 0;
	int maxCount = arr[0];
	int maxCountCount = 1;
	for (int i = 1; i < 26; i++) {
		if (maxCount < arr[i]) {
			maxIndex = i;
			maxCount = arr[i];
			maxCountCount = 1;
		}
		if (maxIndex != i && maxCount == arr[i]) {
			maxCountCount++;
		}
	}

	char c = maxIndex + 'A';
	if (maxCountCount > 1)
		cout << "?" << endl;
	else
		cout << c << endl;
}