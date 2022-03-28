#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n_case;
	cin >> n_case;
	int dy_array[12] = { 1,2,4, };

	for (int i = 3; i < 12; i++) {
		dy_array[i] = dy_array[i - 1] + dy_array[i - 2] + dy_array[i - 3];
	}
	for (int i = 0; i < n_case; i++) {
		int k;
		cin >> k;
		cout << dy_array[k - 1] << endl;
	}

	return 0;
}