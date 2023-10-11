#include <iostream>
#include <string>

using namespace std;


int quad_tree_search(char arr[][65], int start_x, int start_y, int end_x, int end_y) {
	
	/*바닥 조건*/
	if (end_x - start_x == 1) {
		cout << arr[start_x][start_y];
		return 0;
	}
	else {
		int same = 1;
		char base = arr[start_x][start_y];
		for (int i = start_x; i < end_x; i++) {
			for (int j = start_y; j < end_y; j++) {
				if (arr[i][j] != base) {
					same = 0;
				}
			}
			if (same == 0)break;
		}
		if (same==1) {
			cout << arr[start_x][start_y];
			return 0;
		}
		else {
			/*넣어줄 인덱스 계산*/
			int mid_x = (start_x + end_x) / 2;
			int mid_y = (start_y + end_y) / 2;
			cout << "(";
			quad_tree_search(arr, start_x, start_y, mid_x, mid_y);
			quad_tree_search(arr, start_x, mid_y, mid_x, end_y);
			quad_tree_search(arr, mid_x, start_y, end_x, mid_y);
			quad_tree_search(arr, mid_x, mid_y, end_x, end_y);
			cout << ")";
		}
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	char arr[64][65];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	quad_tree_search(arr, 0, 0, n, n);


	return 0;

	
}