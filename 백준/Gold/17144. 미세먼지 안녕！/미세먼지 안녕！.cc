#include <iostream>
#include <deque>
#include <vector>
#include <cstring>

using namespace std;

int R, C, T;
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { 1, -1, 0, 0 };
int room[52][52];
int tmp_room[52][52];
vector<pair<int, int>> cl; //공기청정기 시계방향 좌표
vector<pair<int, int>> uncl; //공기 청정기 반시계방향 좌표
vector<int> air;


//먼지 확산 함수
void spread(int x, int y) {
	int nx, ny;
	int spread_count = 0; // 먼지 확산되는 범위
	int spread_amount; // 먼지 확산 양

	vector<pair<int, int>> tmp;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i], ny = y + dy[i];
		if (room[nx][ny] != -1) {
			tmp.push_back({ nx, ny });
			spread_count++;
		}
	}
	spread_amount = room[x][y] / 5;
	for (auto& sp : tmp) {
		tmp_room[sp.first][sp.second] += spread_amount;
	}
	tmp_room[x][y] += room[x][y] - (spread_amount * spread_count);
}

void rotation_uncl() {
	deque<int> d;

	//반시계 방향 으로 값을 넣어준다.
	for (auto& pos : uncl) {
		d.push_back(room[pos.first][pos.second]);
	}
	d.push_front(0);// 0으로 한 칸 밀고
	d.pop_back(); // 맨 뒷값 하나 없앤다.

	for (auto& pos : uncl) {
		room[pos.first][pos.second] = d.front();
		d.pop_front();
	}
}

void rotation_cl() {
	deque<int> d;
	for (auto& pos : cl) {
		d.push_back(room[pos.first][pos.second]);
	}
	d.push_front(0);// 0으로 한 칸 밀고
	d.pop_back(); // 맨 뒷값 하나 없앤다.

	for (auto& pos : cl) {
		room[pos.first][pos.second] = d.front();
		d.pop_front();
	}
}

int main() {
	cin >> R >> C >> T;
	//패딩 작업
	for (int i = 0; i <= C + 1; i++) {
		room[0][i] = room[R + 1][i] = -1;
	}
	for (int i = 0; i <= R + 1; i++) {
		room[i][0] = room[i][C + 1] = -1;
	}
	// 입력
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> room[i][j];
		}
	}

	//공기 청정기가 정화하는 좌표를 차례대로 넣어준다.
	for (int i = 1; i <= R; i++) {
		if (room[i][1] == -1) air.push_back(i);
	}

	// 반시계 방향
	for (int i = 2; i <= C; i++) {
		uncl.push_back({ air[0], i});
	}
	for (int i = air[0] - 1; i > 0; i --) {
		uncl.push_back({ i, C });
	}
	for (int i = C - 1; i > 0; i--) {
		uncl.push_back({ 1, i });
	}
	for (int i = 2; i < air[0]; i++) {
		uncl.push_back({ i, 1 });
	}

	//시계 방향
	for (int i = 2; i <= C; i++) {
		cl.push_back({ air[1], i});
	}
	for (int i = air[1] + 1; i <= R; i++) {
		cl.push_back({ i, C });
	}
	for (int i = C - 1; i > 0; i--) {
		cl.push_back({ R, i });
	}
	for (int i = R - 1; i > air[1]; i--) {
		cl.push_back({ i,1 });
	}


	while (T > 0) {
		T --;
		//먼지 확산
		memset(tmp_room, 0, sizeof(tmp_room));
		tmp_room[air[0]][1] = tmp_room[air[1]][1] = -1;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (room[i][j] > 0) spread(i, j);
			}
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				room[i][j] = tmp_room[i][j];
			}
		}
		//공기청정기로 한 바퀴 돌기
		rotation_cl();
		rotation_uncl();

	}
	int result = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (room[i][j] > 0) {
				result += room[i][j];
			}
		}
	}
	cout << result;

}