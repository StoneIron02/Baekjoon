#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct vertex {
	int id;
	set<int, greater<int>> adj;
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
void DFS(graph& G, vertex* u) {
	u->visited = cnt++;
	for (int id : u->adj) {
		vertex* v = G.vertexList[id];
		if (v->visited == 0)
			DFS(G, v);
	}
}
void DFS(graph& G, int uId) {
	DFS(G, G.vertexList[uId]);
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
	DFS(G, r);
	for (vertex* v : G.vertexList) {
		if (v != NULL)
			cout << v->visited << "\n";
	}
}