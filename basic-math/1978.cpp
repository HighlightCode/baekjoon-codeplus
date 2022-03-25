#include <iostream>

using namespace std;


int main() {
	int prime[1000+1] = { 0, };
	prime[1] = 1;
	for (int i = 2; i < 1000; i++) {
		for (int j = 2; i * j <= 1000; j++) {
			prime[i * j] = 1;
		}
	}

	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (prime[k] == 0)
			cnt += 1;
	}
	cout << cnt << endl;

}