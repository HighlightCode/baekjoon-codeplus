#include <algorithm>
#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

int min_tsp(int n, vector<vector<int>> price) {
	int max_price = INT_MAX;
	vector<int> permute;
	for (int i = 0; i < n; i++) {
		permute.push_back(i);
	}

	do {
		int cal = 0;
		bool go = true;
		for (int i = 1; i < n; i++) {
			int x = permute[i];
			int p_x = permute[i - 1];
			if (price[p_x][x] == 0) {
				go = false;
				break;
			}
			cal += price[p_x][x];
			if (cal > max_price) {
				go = false;
				break;
			}
		}
		int p_x = permute[n - 1];
		int x = permute[0];
		if (price[p_x][x] == 0)
			go = false;
		cal += price[p_x][x];
		if (go)
			max_price = min(max_price, cal);
	} while (next_permutation(permute.begin(), permute.end()));

	return max_price;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> tsp_route;
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			tmp.push_back(k);
		}
		tsp_route.push_back(tmp);
	}
	cout << min_tsp(n, tsp_route);

}