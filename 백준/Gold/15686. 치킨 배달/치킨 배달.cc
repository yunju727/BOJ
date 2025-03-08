#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int city[50][50];
int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<int> result;

int manhattan_distance(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}


int calculate_chicken_distance(vector<pair<int, int>>& selected_chickens) {
	int total_distance = 0;
	for (auto& house : houses) {
		int min_distance = 200;
		for (auto& chicken : selected_chickens) {
			min_distance = min(min_distance, manhattan_distance(house, chicken));
		}
		total_distance += min_distance;
	}
	return total_distance;
}

void select_chickens(int idx, int count, vector<pair<int, int>>& selected_chickens) {
	if (count == M) {
		int distance = calculate_chicken_distance(selected_chickens);
		result.push_back(distance);
		return;
	}
	if (idx >= chickens.size())return;
	selected_chickens.push_back(chickens[idx]);
	select_chickens(idx + 1, count + 1, selected_chickens);
	selected_chickens.pop_back();
	select_chickens(idx + 1, count, selected_chickens);
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 2) {
				chickens.push_back({ i, j });
			}
			else if (city[i][j] == 1) {
				houses.push_back({ i,j });
			}
		}
	}
	vector<pair<int, int>> selected_chickens;
	select_chickens(0, 0, selected_chickens);

	cout << *min_element(result.begin(), result.end());
}