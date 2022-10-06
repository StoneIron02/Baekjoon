#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	vector<int> arr(3);
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr.begin(), arr.end());
	cout << arr[1];	
}