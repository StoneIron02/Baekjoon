#include <iostream>
#include <cmath>
using namespace std;

int find(int num, int N, int r, int c, int len) {
	if (N == 0) {
		return num;
	}

	int sublen = len / 2;
	int total = pow(len, 2);

	if (r < sublen) { // 위쪽
		if (c < sublen) { // 위쪽 & 왼쪽
			num += (total / 4) * 0;
		}
		else { // 위쪽 & 오른쪽
			c -= sublen;
			num += (total / 4) * 1;
		}
	}
	else { // 아래쪽
		r -= sublen;
		if (c < sublen) { // 아래쪽 & 왼쪽
			num += (total / 4) * 2;
		}
		else { // 아래쪽 & 오른쪽
			c -= sublen;
			num += (total / 4) * 3;
		}
	}

	return find(num, N - 1, r, c, sublen);
}

int main() {
	int N, r, c;
	cin >> N  >> r >> c;

	int len = pow(2, N);
	cout << find(0, N, r, c, len);
}

// N  r  c  num
// 3  7  7  0
// 2  3  3  48
// 1  1  1  60
// 0  0  0  63

//1 -> 4 -> 1
//2 -> 16 -> 4
//3 -> 64 -> 16

// 2 * 2 : (0,0) -> (0,1) -> (1,0) -> (1,1)
// 4 * 4 : (0,0) -> (0,1) -> (1,0) -> (1,1) -> (0,2) -> (0,3) -> (1,2) -> (1,3) -> 
//		   (2,0) -> (2,1) -> (3,0) -> (3,1) -> (2,2) -> (2,3) -> (3,2) -> (3,3)
// 8 * 8 : (0,0) -> (0,1) -> (1,0) -> (1,1) -> (0,2) -> (0,3) -> (1,2) -> (1,3) -> 
//		   (2,0) -> (2,1) -> (3,0) -> (3,1) -> (2,2) -> (2,3) -> (3,2) -> (3,3) -> 
//		   (0,4) -> (0,5) -> (1,4) -> (1,5) -> (0,6) -> (0,7) -> (1,6) -> (1,7) -> 
//		   (2,4) -> (2,5) -> (3,4) -> (3,5) -> (2,6) -> (2,7) -> (3,6) -> (3,7) -> 
//		   (4,0) -> ...