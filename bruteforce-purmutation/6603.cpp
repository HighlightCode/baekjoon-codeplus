#include <algorithm>
#include <vector>
#include <iostream>


using namespace std;

void print_lotto(int n) {
	vector<int> tmp;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		tmp.push_back(k);
	}
	vector<int> lotto;
	for (int i = 0; i < n; i++) {
		if (i < 6)
			lotto.push_back(0);
		else
			lotto.push_back(1);
	}

	do {
		for (int i = 0; i < n; i++) {
			if (lotto[i] == 0)
				cout << tmp[i] << " ";
		}
		cout << endl;
	} while (next_permutation(lotto.begin(), lotto.end()));

	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;	
		print_lotto(n);
	}
	return 0;
}