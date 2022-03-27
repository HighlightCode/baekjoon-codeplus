#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int calculator(int m, int n, int x, int y) {
	int result = 1;
	int lcm_result = m * n / gcd(m, n);
	while (result < lcm_result) {
		if ((result - x) % m == 0 && (result - y) % n == 0) {
			return result;
		}
		else if ((result-x) %m !=0) {
			result += 1;
		}
		else {
			result += m;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num_test;
	cin >> num_test;

	for (int i = 0; i < num_test; i++) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		cout << calculator(m, n, x, y) << endl;
	}

	return 0;
}