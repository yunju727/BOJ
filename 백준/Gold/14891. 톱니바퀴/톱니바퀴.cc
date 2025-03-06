#include <iostream>
#include <string>

using namespace std;

int rotation[4] = { 0, 0, 0 ,0 };
int temp_rotation[4] = { 0, 0, 0, 0 };

// 회전 후 인덱스 계산
int rotation_idx(int x) {
	if (x < 0) {
		while (x < 0) {
			x += 8;
		}
	}
	else if (x >= 8) {
		x %= 8;
	}
	return x;
}

int main() {
	string topni[4];

	for (int i = 0; i < 4; i++) {
		cin >> topni[i];
	}
	
	int x;
	cin >> x;

	for (int i = 0; i < x; i++) {
		int n, dir;
		cin >> n >> dir;
		temp_rotation[n - 1] -= dir;
		// 회전 톱니바퀴 기준 왼쪽 톱니바퀴 순회
		int temp_dir = - dir;
		for (int j = n - 1; j > 0; j--) {
			if (topni[j][rotation_idx(rotation[j] + 6)] != topni[j - 1][rotation_idx(rotation[j - 1] + 2)]) {
				temp_rotation[j - 1] -= temp_dir;
				temp_dir = - temp_dir;
			}
			else break;
		}
		temp_dir = -dir;
		for (int j = n - 1; j < 3; j++) {
			if (topni[j][rotation_idx(rotation[j] + 2)] != topni[j + 1][rotation_idx(rotation[j + 1] + 6)]) {
				temp_rotation[j + 1] -= temp_dir;
				temp_dir = -temp_dir;
			}
			else break;
		}

		for (int k = 0; k < 4; k++) {
			rotation[k] = temp_rotation[k];
		}
	}
	int score = 1;
	int result = 0;

	for (int i = 0; i < 4; i++) {

		if (topni[i][rotation_idx(rotation[i])] == '1') {
			result += score;
		}
		score *= 2;
	}
	cout << result;
}