#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N, K, L;
deque<pair<int, int>> snake;

//오른쪽 회전 시, 뱀의 방향 +1, 왼쪽 회전 시, 뱀의 방향 -1
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

// 뱀의 회전 방향 보정
int rotate_num(int dir) {
	if (dir > 3) return dir - 4;
	else if (dir < 0) return dir + 4;
	else return dir;
}

// 뱀의 머리 위치가 격자를 벗어나는지 검사하는 함수
// 벗어나면 false return
bool game_over1(pair<int, int> position) {
	return position.first >= 0 && position.first < N && position.second >= 0 && position.second < N;
}

bool game_over2(pair<int, int> position, deque<pair<int, int>>& snake) {

	for (auto it = snake.begin(); it != snake.end(); ++it) {
		int body_x = (*it).first;
		int body_y = (*it).second;
		if (body_x == position.first && body_y == position.second) {
			return true;
		}
	}
	return false;

}

int main() {
	vector<pair<int, int>> apples;
	queue<pair<int, char>> rotations;

	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		apples.push_back({ x - 1, y - 1 });
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		int x;
		char d;
		cin >> x >> d;
		rotations.push({ x, d });
	}

	// 뱀 위치 초기화, 머리 위치와 방향은 따로 변수에 저장해준다.
	int x = 0;
	int y = 0;
	int d = 0;

	int count = 0;

	while (game_over1({ x, y })) {
		if (game_over2({ x, y }, snake)) {
			break;
		}
		// 사과 있는지 확인하기
		bool is_apple = false;
		for (auto it = apples.begin(); it != apples.end(); ++it) {
			if (it->first == x && it->second == y) {
				is_apple = true;
				apples.erase(it);  // 사과 벡터에서 삭제
				break;  // 사과 하나 먹었으므로 루프 종료
			}
		}
		if (!is_apple && !snake.empty()) {
			snake.pop_back();
		}

		snake.push_front({ x, y });

		// 방향 전환
		if (!rotations.empty()) {
			pair<int, char> tmp = rotations.front();
			if (tmp.first == count) {
				if (tmp.second == 'D') d += 1;
				else if (tmp.second == 'L') d -= 1;
				rotations.pop();
			}
		}

		//시간 증가 시키고, 뱀 머리 이동 ~
		count += 1;
		d = rotate_num(d);
		x += dx[d];
		y += dy[d];
	}

	cout << count;
}