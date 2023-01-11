#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

struct vertex {
	int id;
	set<int> adj;
	int visited;
	vertex(int id) : id(id), visited(0) {
	}
};

class graph {
public:
	graph() {
	}
	graph(int startVertexId) {
		vertexList.resize(startVertexId);
		for (int i = 0; i < startVertexId; i++)
			vertexList.push_back(NULL);
	}

	void insertVertex(int id) {
		vertexList.insert(vertexList.begin() + id, new vertex(id));
	}

	void insertEdge(int sourceId, int destinationId) {
		vertexList[sourceId]->adj.insert(destinationId);
	}
	void insertEdgeUndir(int sourceId, int destinationId) {
		vertexList[sourceId]->adj.insert(destinationId);
		vertexList[destinationId]->adj.insert(sourceId);
	}

	vector<vertex*> vertexList;
};

int cnt = 1;
void BFS(graph& G, int sId) {
	vertex* s = G.vertexList[sId];
	for (vertex* u : G.vertexList) {
		if (u != nullptr)
			u->visited = 0;
	}
	queue<vertex*> queue;
	queue.push(s);
	s->visited = cnt++;
	while (!queue.empty()) {
		vertex* u = queue.front();
		queue.pop();
		for (int id : u->adj) {
			vertex* v = G.vertexList[id];
			if (v->visited == 0) {
				queue.push(v);
				v->visited = cnt++;
			}
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m, r;
	cin >> n >> m >> r;
	graph G(1);
	for (int i = 1; i <= n; i++)
		G.insertVertex(i);

	for (int i = 0; i < m; i++) {
		int s, d;
		cin >> s >> d;
		G.insertEdgeUndir(s, d);
	}
	BFS(G, r);
	for (vertex* v : G.vertexList) {
		if (v != NULL)
			cout << v->visited << "\n";
	}
}