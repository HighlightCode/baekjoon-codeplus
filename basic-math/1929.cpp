#include <iostream>
#include <cmath>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	bool prime[1000000 + 1] = { 0, };
	prime[1] = 1;
	for (int i = 2; i <= sqrt(m); i++) {
		if (prime[i] != 1) {
			for (int j = i*2 ; j <= m; j += i) {
				prime[j] = 1;
			}
		}
	}

	for (int i = n; i <= m; i++) {
		if (prime[i] == 0)
			cout << i << "\n";
	}

}