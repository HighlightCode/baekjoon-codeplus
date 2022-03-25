#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);

	bool is_prime[1000000 + 1] = { true, };
	memset(is_prime, true, sizeof(is_prime));

	for (int i = 2; i <= 1000; i++) {
		if (is_prime[i] == true) {
			for (int j = i * 2; j <= 1000000; j+=i) {
				is_prime[j] = false;
			}
		}
	}

	int k;
	while (cin >> k) {
		if (k == 0) {
			break;
		}
		else {
			for (int i = 3; i < 500000; i+=2) {
				if (is_prime[i] == true && is_prime[k - i] == true) {
					cout << k << " = " << i << " + " << k - i << "\n";
					break;
				}
			}
		}
	}

}