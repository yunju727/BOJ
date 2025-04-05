#include <iostream>
#include <queue>

using namespace std;

int graph[1001][1001], N, M, V;
int visited_dfs[1001], visited_bfs[1001];

void DFS(int v) {
	cout << v << " ";
	visited_dfs[v] = 1;

	for (int i = 1; i <= N; i++) {
		if (!visited_dfs[i] && graph[v][i]) {
			DFS(i);
		}
	}
}

void BFS(int v) {
	queue<int> q;
	q.push(v);
	visited_bfs[v] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 1; i <= N; i++) {
			if (!visited_bfs[i] && graph[cur][i]) {
				q.push(i);
				visited_bfs[i] = 1;
			}
		}
	}

}


int main() {

	for (int i = 0; i < 1001; i++) {
		visited_dfs[i] = 0; visited_bfs[i] = 0;
	}
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1][n2] = 1; graph[n2][n1] = 1;
	}
	DFS(V);
	cout << endl;
	BFS(V);

}