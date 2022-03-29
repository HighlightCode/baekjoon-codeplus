#include <algorithm>
#include <vector>
#include <iostream>


using namespace std;


int main() {
	int n;
	cin >> n;

	vector<int> tmp;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		tmp.push_back(k);
	}

	sort(tmp.begin(), tmp.end());
	int max_num = 0;
	//reverse(tmp.begin(), tmp.end());
	do {
		int tmp_num = 0;
		for (int i = 0; i < n-1; i++) {
			tmp_num += abs(tmp[i + 1] - tmp[i]);
		}
		max_num = max(tmp_num, max_num);
	} while (next_permutation(tmp.begin(), tmp.end()));

	cout << max_num;
}