#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	long long ans = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int tmp = n / i;
		tmp *= i;
		ans += tmp;
	}

	cout << ans;
}