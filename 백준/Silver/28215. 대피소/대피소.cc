#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, dis[50][50];
vector<pair<int, int>> houses;
vector<int> max_distance;
vector<int> s;


void backtracking(int idx) {
	if (idx == K) {
		int tmp_max = 0;
		for (int i = 0; i < N; i++) {
			long long tmp_min = 300000;
			for (int j = 0; j < idx; j++) {
				tmp_min = tmp_min > dis[s[j]][i] ? dis[s[j]][i] : tmp_min;
			}
			tmp_max = tmp_max < tmp_min ? tmp_min : tmp_max;
		}
		max_distance.push_back(tmp_max);
		return;
	}
	int select_idx = s.empty() ? 0 : s[idx - 1];
	for (int i = select_idx; i < N; i++) {
		s.push_back(i);
		backtracking(idx + 1);
		s.pop_back();
	}
}


int main() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			dis[i][j] = 0;
		}
	}

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int tmp_x, tmp_y;
		cin >> tmp_x >> tmp_y;
		houses.push_back({ tmp_x, tmp_y });
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x1, x2, y1, y2, dis_x, dis_y;
			x1 = houses[i].first; x2 = houses[j].first;
			y1 = houses[i].second; y2 = houses[j].second;
			dis_x = x1 - x2; dis_y = y1 - y2;
			dis_x = dis_x > 0 ? dis_x : -dis_x;
			dis_y = dis_y > 0 ? dis_y : -dis_y;
			dis[i][j] = dis_x + dis_y;
		}
	}
	backtracking(0);
	cout << *min_element(max_distance.begin(), max_distance.end());


}