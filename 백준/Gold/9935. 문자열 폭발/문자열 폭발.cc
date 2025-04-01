#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
	string start, bomb;
	vector<char> s;

	cin >> start;
	cin >> bomb;
	int b_len = bomb.length();

	for (int i = 0; i < start.length(); i++) {
		s.push_back(start[i]);
		if (i >= (b_len - 1) && s[s.size()-1] == bomb[b_len - 1]) {
			bool is_equal = true;
			for (int j = 0; j < b_len; j++) {
				if (s[s.size() - j - 1] != bomb[b_len - j - 1]) {
					is_equal = false;
					break;
				}
			}
			if (is_equal) {
				for (int k = 0; k < b_len; k++) {
					s.pop_back();
				}
			}
		}
	}

	if (s.empty()) {
		cout << "FRULA";
	}
	else {
		for (auto& st : s) {
			cout << st;
		}
	}
	
}