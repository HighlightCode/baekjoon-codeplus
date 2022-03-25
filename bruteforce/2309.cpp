#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> height(9);
	int sum_height = 0;

	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum_height += height[i];
	}
	sort(height.begin(), height.end());

	bool find = false;

	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
			if (sum_height - height[i] - height[j] == 100) {
				find == true;
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j)
						cout << height[k] << endl;
				}
				return 0;
			}
		}
	}
	return 0;
}