#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N, M, box[1002][1002];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
deque<pair<int, int>> tomorrow;

int main() {
	cin >> M >> N;
	//padding
	for (int i = 0; i <= N + 1; i++) {
		box[i][0] = box[i][M + 1] = -1;
	}
	for (int i = 0; i <= M + 1; i++) {
		box[0][i] = box[N + 1][i] = -1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1)tomorrow.push_back({ i, j });
		}
	}
	int day = 0;

	while (!tomorrow.empty()) {
		int c = tomorrow.size();
		for (int i = 0; i < c; i++) {
			pair<int, int> tomato = tomorrow.front();
			tomorrow.pop_front();
			for (int i = 0; i < 4; i++) {
				int nx = tomato.first + dx[i], ny = tomato.second + dy[i];
				if (box[nx][ny] == 0) {
					tomorrow.push_back({ nx, ny });
					box[nx][ny] = 1;
				}
			}
		}
		day += 1;
	}

	bool law_tomato = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (box[i][j] == 0) {
				law_tomato = true;
				break;
			}
		}
	}

	if (law_tomato)cout << -1;
	else cout << day-1;
}
