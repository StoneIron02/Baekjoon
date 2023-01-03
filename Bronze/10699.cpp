#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	time_t now = time(NULL);
	tm* nowtm = localtime(&now);
	cout << (nowtm->tm_year + 1900) << "-" << (nowtm->tm_mon + 1) << "-" << nowtm->tm_mday;
}