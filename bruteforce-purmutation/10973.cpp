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
		tmp.push_back(-k);
	}

	//reverse(tmp.begin(), tmp.end());
	if (next_permutation(tmp.begin(), tmp.end())) {
		for (int i = 0; i < n; i++) {
			cout << -tmp[i] << " ";
		}
	}
	else {
		cout << -1 << endl;
	}
}