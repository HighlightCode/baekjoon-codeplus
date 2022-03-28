#include<iostream>
#include <vector>
#include <limits.h>
#include<algorithm>

using namespace std;


int calculate(vector<bool> &s_l, vector<vector<int>> &point) {
	int s_point = 0;
	int l_point = 0;
	vector<int> s_p;
	vector<int> l_p;

	for (int i = 0; i < s_l.size(); i++) {
		if (s_l[i] == true)
			s_p.push_back(i);
		else
			l_p.push_back(i);
	}

	for (int i = 0; i < s_p.size(); i++) {
		int x = s_p[i];
		for (int j = 0; j < s_p.size(); j++) {
			int y = s_p[j];
			s_point += point[x][y];
		}
	}

	for (int i = 0; i < l_p.size(); i++) {
		int x = l_p[i];
		for (int j = 0; j < l_p.size(); j++) {
			int y = l_p[j];
			l_point += point[x][y];
		}
	}
	return abs(s_point - l_point);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	
	vector<bool> s_l;
	vector<vector<int>> point_sl;
	int result = INT_MAX;

	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < N; j++) {
			int k;
			cin >> k;
			tmp.push_back(k);
		}
		point_sl.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		if (i < N / 2)
			s_l.push_back(0);
		else
			s_l.push_back(1);
	}

	while (true) {
		if (next_permutation(s_l.begin(), s_l.end())) {
			result = min(result, calculate(s_l, point_sl));
		}
		else {
			break;
		}
	}

	cout << result;
	return 0;
}