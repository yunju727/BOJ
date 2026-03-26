#include <iostream>

using namespace std;


int N, M = 0;

bool isPrime(int x) {
	bool isPrimeNum = true;
	if (x == 1)return false;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	int result = 0;
	int minPrime = 0;
	cin >> N >> M;
	for (int i = N; i <= M; i++) {
		if (isPrime(i)) {
			result += i;
			if (minPrime == 0)minPrime = i;
		}
	}
	if (result != 0) {
		cout << result << "\n" << minPrime;
	}
	else {
		cout << -1;
	}
	
}