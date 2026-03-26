#include <iostream>

using namespace std;


int N, M = 0;

void isPrime(int x) {
	bool isPrimeNum = true;
	if (x == 1)isPrimeNum = false;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			isPrimeNum = false;
			break;
		}
	}
	if (isPrimeNum)cout << x << "\n";
}

int main() {
	cin >> N >> M;
	for (int i = N; i <= M; i++) {
		isPrime(i);
	}
	
}