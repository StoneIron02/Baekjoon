#include <iostream>
using namespace std;

int main() {
	int king, queen, look, bishop, knight, pawn;
	cin >> king >> queen >> look >> bishop >> knight >> pawn;
	cout << (1 - king) << " ";
	cout << (1 - queen) << " ";
	cout << (2 - look) << " ";
	cout << (2 - bishop) << " ";
	cout << (2 - knight) << " ";
	cout << (8 - pawn) << "\n";
}