#include <algorithm>
#include <vector>
#include <iostream>


using namespace std;


int main() {
	int n;
	cin >> n;

	vector<int> tmp;
	for (int i = 0; i < n; i++) {
		tmp.push_back(i+1);
	}

	//reverse(tmp.begin(), tmp.end());
	do {
		for (int i = 0; i < n; i++) {
			cout << tmp[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(tmp.begin(), tmp.end()));
}