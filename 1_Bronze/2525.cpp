#include <iostream>
using namespace std;

int main() {
	int hour, min;
	cin >> hour >> min;
	int cook_time;
	cin >> cook_time;

	int now = hour * 60 + min;
	int result = now + cook_time;

	int result_hour = (result / 60) % 24;
	int result_min = result % 60;
	cout << result_hour << " " << result_min;
}