#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct activity {
	int start;
	int end;
	activity() : start(-1), end(-1) {
	}
	activity(int start, int end) : start(start), end(end) {
	}
	friend ostream& operator<<(ostream& out, activity& ac) {
		out << "(" << ac.start << ", " << ac.end << ")";
		return out;
	}
};

bool compare(activity& ac1, activity& ac2) {
	if (ac1.end == ac2.end)
		return (ac1.start < ac2.start);
	return (ac1.end < ac2.end);
}

vector<activity> ACTIVITY_SELECTOR(activity* activities, int n) {
	vector<activity> selected;
	selected.push_back(activities[0]);
	int k = 0;
	for (int m = 1; m < n; m++) {
		if (activities[m].start >= activities[k].end) {
			selected.push_back(activities[m]);
			k = m;
		}
	}
	return selected;
}

int ACTIVITY_SELECTOR_size(vector<activity>& selected) {
	return selected.size();
}

int main() {
	int n;
	cin >> n;
	activity* activities = new activity[n];
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		activities[i] = activity(start, end);
	}
	sort(activities, activities + n, compare);
	vector<activity> selected = ACTIVITY_SELECTOR(activities, n);
	cout << ACTIVITY_SELECTOR_size(selected);
}