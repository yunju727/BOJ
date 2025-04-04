#include <iostream>
#include <vector>
using namespace std;

int main() {
	long n, B, C;
	vector<long> students;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		students.push_back(tmp);
	}
	cin >> B >> C;
	long result = 0;
	for (auto& student : students) {
		long tmp;
		if (student - B > 0) {
			tmp = (student - B) % C > 0 ? 2 + (student - B) / C : 1 + (student - B) / C;
		}
		else {
			tmp = 1;
		}
		result += tmp;
	}

	cout << result;
	
}