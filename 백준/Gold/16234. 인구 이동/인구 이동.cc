#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, L, R;
int graph[50][50];
int visited[50][50];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> association;

//limit 검사하는 함수
bool is_limit(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

//BFS 하는 함수
/*
pair<int, int> BFS(int x, int y) {
	association.clear();
	int c = 0;
	int p = 0;
	int nx, ny;
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		nx = q.front().first;
		ny = q.front().second;
		association.push_back({ nx, ny });
		visited[nx][ny] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = q.front().first + dx[i];
			int ny = q.front().second + dy[i];
			if (is_limit(nx, ny)) {
				int distance = abs(graph[q.front().first][q.front().second] - graph[nx][ny]);
				if (distance >= L && distance <= R) {
					q.push({ nx, ny });
					visited[nx][ny] = 1;
				}
			}
		}
		p += graph[q.front().first][q.front().second];
		c += 1;
		q.pop();
	}
	//만약 연합하는 도시가 없다면 c에 1이 리턴 될 것임
	return { p, c };

}
*/


pair<int, int> BFS(int x, int y) {
	association.clear();
	queue<pair<int, int>> q;

	q.push({ x, y });       // 🔹 처음 탐색 시작 노드를 큐에 넣음
	visited[x][y] = 1;    // 🔥 처음 방문 처리 (중복 방문 방지)

	int total_population = 0;
	int count = 0;

	while (!q.empty()) {
		pair<int,int> k = q.front();
		q.pop();

		association.push_back({ k.first, k.second});
		total_population += graph[k.first][k.second];
		count++;

		for (int i = 0; i < 4; i++) {
			int nx = k.first + dx[i];
			int ny = k.second + dy[i];

			if (is_limit(nx, ny) && !visited[nx][ny]) {
				int distance = abs(graph[k.first][k.second] - graph[nx][ny]);
				if (distance >= L && distance <= R) {
					q.push({ nx, ny });
					visited[nx][ny] = 1; // 🔥 큐에 넣을 때 방문 처리
				}
			}
		}
	}

	return { total_population, count };
}
int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	int r = 0;
	bool is_association;
	do {
		//visited 배열 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 0;
			}
		}
		is_association = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					pair<int, int> result = BFS(i, j);

					if (result.second > 1) {
						is_association = true;
						int people = result.first / result.second;
						for (auto& pos : association) {
							graph[pos.first][pos.second] = people;
						}
					}
				}
			}
		}
		if (is_association)r++;

	} while (is_association);

	cout << r;
}
