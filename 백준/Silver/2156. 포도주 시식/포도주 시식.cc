#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	vector<int> data(n), dp(n + 1, 0);
	for (auto& iter : data)
		cin >> iter;

	dp[1] = data[0];
	dp[2] = data[1] + data[0];
	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(data[i - 1] + data[i - 2] + dp[i - 3], data[i - 1] + dp[i - 2]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << dp[n] << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
