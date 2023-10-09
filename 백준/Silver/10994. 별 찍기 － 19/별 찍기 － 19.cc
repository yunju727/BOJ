#include <iostream>


using namespace std;

int draw_star(int n, char **a, int size) {
	if (n == 1) {
		int draw_size = 4 * size - 3;
		int mid = draw_size / 2;
		a[mid][mid] = '*';
		return 0;
	}
	else {
		int next_n = n - 1;
		int draw_size = 4 * n - 3;
		int start_spot = 2 * (size - n);
		int end_spot = start_spot + draw_size-1;
        
		for (int i = start_spot; i <= end_spot; i++) {
			a[i][start_spot] = '*';
			a[i][end_spot] = '*';
			a[start_spot][i] = '*';
			a[end_spot][i] = '*';
		}
		return draw_star(next_n, a, size);
		
	}
}

int main() {
	int n;
	cin >> n;
	int size = 4 * n - 3;

	char** arr = new char* [size];
	for (int i = 0; i < size; i++) {
		arr[i] = new char[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size;  j++) {
			arr[i][j] = ' ';
		}
	}
	draw_star(n, arr, n);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}