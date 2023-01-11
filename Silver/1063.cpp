#include <iostream>
#include <string>
using namespace std;

pair<int, int> positionKing;
pair<int, int> positionStone;
int n;

bool isInBoard(pair<int, int> position) {
	return (position.first >= 0 && position.first < 8 && position.second >= 0 && position.second < 8);
}

pair<int, int> getPosition(pair<int, int> origin, int vec_x, int vec_y) {
	return { origin.first + vec_x, origin.second + vec_y };
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	string positionKingStr, positionStoneStr;
	cin >> positionKingStr >> positionStoneStr >> n;
	positionKing = { positionKingStr[0] - 'A', positionKingStr[1] - '1' };
	positionStone = { positionStoneStr[0] - 'A', positionStoneStr[1] - '1' };

	for (int i = 0; i < n; i++) {
		string move;
		cin >> move;
		bool flag = true;
		pair<int, int> movePositionKing;
		pair<int, int> movePositionStone;
		if (move == "L") {
			movePositionKing = getPosition(positionKing, -1, 0);
			movePositionStone = getPosition(positionKing, -2, 0);
		}
		if (move == "R") {
			movePositionKing = getPosition(positionKing, 1, 0);
			movePositionStone = getPosition(positionKing, 2, 0);
		}
		if (move == "T") {
			movePositionKing = getPosition(positionKing, 0, 1);
			movePositionStone = getPosition(positionKing, 0, 2);
		}
		if (move == "B") {
			movePositionKing = getPosition(positionKing, 0, -1);
			movePositionStone = getPosition(positionKing, 0, -2);
		}
		if (move == "LT") {
			movePositionKing = getPosition(positionKing, -1, 1);
			movePositionStone = getPosition(positionKing, -2, 2);
		}
		if (move == "LB") {
			movePositionKing = getPosition(positionKing, -1, -1);
			movePositionStone = getPosition(positionKing, -2, -2);
		}
		if (move == "RT") {
			movePositionKing = getPosition(positionKing, 1, 1);
			movePositionStone = getPosition(positionKing, 2, 2);
		}
		if (move == "RB") {
			movePositionKing = getPosition(positionKing, 1, -1);
			movePositionStone = getPosition(positionKing, 2, -2);
		}
		if (positionStone == movePositionKing) {
			if (!isInBoard(movePositionStone)) continue;
			positionStone = movePositionStone;
			positionKing = movePositionKing;
		}
		else {
			if (!isInBoard(movePositionKing)) continue;
			positionKing = movePositionKing;
		}
	}

	cout << (char)(positionKing.first + 'A') << (char)(positionKing.second + '1') << "\n";
	cout << (char)(positionStone.first + 'A') << (char)(positionStone.second + '1') << "\n";
}