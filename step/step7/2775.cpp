#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int k, n;
		cin >> k;
		cin >> n;

		int count = 0;
		for (int w = 1; w <= n; w++) {
			for (int v = 1; v <= w; v++) {

			}
		}
	}
}


/*
1 1+(1+(1+2))	1+(1+(1+2))+(1+(1+2)+(1+2+3))
1 1+(1+2)	1+(1+2)+(1+2+3)
1 1+2  		1+2+3		1+2+3+4		  1+2+3+4+5
1  2  		3		  4		   5
*/