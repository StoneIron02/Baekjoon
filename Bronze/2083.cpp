#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	while (true) {
		string name;
		int age;
		int weight;
		cin >> name >> age >> weight;

		if (name == "#" && age == 0 && weight == 0)
			exit(0);

		if (age > 17 || weight >= 80)
			cout << name << " Senior\n";
		else
			cout << name << " Junior\n";
	}
}