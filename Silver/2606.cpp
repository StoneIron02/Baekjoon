#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

struct vertex {
	int id;
	set<int> adj;
	bool visited;
	vertex(int id) : id(id), visited(false) {
	}
};

class graph {
public:
	graph() {
	}
	graph(int startVertexId) {
		vertexList.resize(startVertexId);
	}
	vertex* operator[](int id) {
		return vertexList[id];
	}

	vector<vertex*>& getVertexList() {
		return vertexList;
	}

	void insertVertex(int id) {
		vertexList.insert(vertexList.begin() + id, new vertex(id));
	}

	void eraseVertex(int id) {
		for (vertex* v : vertexList) {
			if (v != nullptr && v->id != id) {
				eraseEdge(v->id, id);
			}
		}
		delete vertexList[id];
	}

	void insertEdge(int sourceId, int destinationId) {
		vertexList[sourceId]->adj.insert(destinationId);
	}

	void eraseEdge(int sourceId, int destinationId) {
		vertexList[sourceId]->adj.erase(destinationId);
	}
private:
	vector<vertex*> vertexList;
};

int cnt = 0;
void BFS(graph& G, int sId) {
	vertex* s = G[sId];
	for (vertex* u : G.getVertexList()) {
		if (u != nullptr)
			u->visited = false;
	}
	queue<vertex*> queue;
	queue.push(s);
	s->visited = true;
	while (!queue.empty()) {
		vertex* u = queue.front();
		queue.pop();
		for (int id : u->adj) {
			vertex* v = G[id];
			if (v->visited == 0) {
				queue.push(v);
				v->visited = true;
				cnt++;
			}
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	graph G(1);
	for (int i = 1; i <= n; i++) {
		G.insertVertex(i);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, d;
		cin >> s >> d;
		G.insertEdge(s, d);
		G.insertEdge(d, s);
	}
	BFS(G, 1);
	cout << cnt;
}