#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 16;
int N, ans;
int T[MAX];
int P[MAX];

void brute(int today, int sum) {
	if (today == N + 1) {
		ans = max(ans, sum);
		return;
	}
	if (today > N) return;

	brute(today + T[today], sum + P[today]);
	brute(today + 1, sum);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	brute(1, 0);

	cout << ans << '\n';
	return 0;
}