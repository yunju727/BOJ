#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int canvas[502][502];
int visited[502][502];
vector<pair<int, int>> picture;
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

//BFS 함수
void BFS(int x, int y) {
	picture.clear();
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;
	picture.push_back({ x,y });

	while (!q.empty()) {
		pair<int, int > k = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = k.first + dx[i], ny = k.second + dy[i];
			if (canvas[nx][ny] == 1 && !visited[nx][ny]) {
				q.push({ nx,ny });
				picture.push_back({ nx, ny });
				visited[nx][ny] = 1;
			}
		}
	}
}

int main() {
	cin >> n >> m;

	//패딩 작업
	for (int i = 0; i <= m + 1; i++) {
		canvas[0][i] = canvas[n + 1][i] = -1;
	}
	for (int i = 0; i <= n + 1; i++) {
		canvas[i][0] = canvas[i][m + 1] = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> canvas[i][j];
		}
	}
	int count = 0;
	int result = 0;
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (canvas[i][j] == 1 && !visited[i][j]) {
				BFS(i, j);
				int picture_size = picture.size();
				if (picture.size() >= 1) {
					count++;
					result = max(result, picture_size); // 새로 알게된 점 : max 함수는 서로 같은 타입이어야함. int-int, unsigned_int-unsigned_int
				}
			}
		}
	}
	cout << count << endl;
	cout << result;
}