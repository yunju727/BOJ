#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

int arr[101][101], max_row, max_col;
int r, c, k;
int dict[101];

int main() {
	cin >> r >> c >> k;
	//인덱스를 1부터 시작하므로 0부터 시작하는걸로 1빼서 맞춰준다.
	r--; c--;
	for (int i = 0; i < 100; i++) {
		dict[i] = 0;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	max_row = 3; max_col = 3;

	int time = 0;
	while (time <= 100) {
		if (arr[r][c] == k) {
			cout << time;
			break;
		}
		time++;
		// 행 수 >= 열 수
		if (max_row >= max_col) {
			for (int i = 0; i < max_row; i++) {
				priority_queue <pair<int, int>> q;
				unordered_set<int> s;
				//dict에 각 원소가 몇 개 있는지 기록해준다.
				for (int j = 0; j < max_col; j++) {
					if (arr[i][j] != 0) {
						s.insert(arr[i][j]);
						dict[arr[i][j]]++;
					}
					arr[i][j] = 0; // 값을 새로운 값으로 바꿔줄거니까
				}
				// 갯수를 센 값을 우선순위 큐에 넣고, dict를 초기화
				for (int x : s) {
					q.push({ -dict[x],-x });
					dict[x] = 0;
				}
				//근데 만약 max_col이 100을 넘으면 그냥 100으로 세팅
				max_col = s.size() * 2 > max_col ? s.size() * 2 : max_col;
				max_col = max_col >= 100 ? 100 : max_col;
				//하나씩 빼서 배열에 세팅
				int num = s.size() >= 50 ? 50 : s.size();
				for (int j = 0; j < num; j++) {
					pair<int, int> k = q.top();
					q.pop();
					arr[i][j*2] = -k.second;
					arr[i][j*2+1] = -k.first;
				}
				while (!q.empty()) {
					q.pop();
				}
				s.clear();
			}
		}
		// 열 수 > 행 수
		else {
			for (int i = 0; i < max_col; i++) {
				priority_queue <pair<int, int>> q;
				unordered_set<int> s;
				//dict에 각 원소가 몇 개 있는지 기록해준다.
				for (int j = 0; j < max_row; j++) {
					if (arr[j][i] != 0) {
						s.insert(arr[j][i]);
						dict[arr[j][i]]++;
					}
					arr[j][i] = 0; // 값을 새로운 값으로 바꿔줄거니까
				}
				// 갯수를 센 값을 우선순위 큐에 넣고, dict를 초기화
				for (int x : s) {
					q.push({ -dict[x],-x });
					dict[x] = 0;
				}
				//근데 만약 max_col이 100을 넘으면 그냥 100으로 세팅
				max_row = s.size() * 2 > max_row ? s.size() * 2 : max_row;
				max_row = max_row >= 100 ? 100 : max_row;
				//하나씩 빼서 배열에 세팅
				int num = s.size() >= 50 ? 50 : s.size();
				for (int j = 0; j < num; j++) {
					pair<int, int> k = q.top();
					q.pop();
					arr[j*2][i] = -k.second;
					arr[j*2+1][i] = -k.first;
				}
				while (!q.empty()) {
					q.pop();
				}
				s.clear();
			}
		}
	}
	if (time > 100)cout << -1;
}
