#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;

void solution()
{
	int n, w;
	cin >> n >> w;

	vector<pii> data(n);
	for (int i = 0; i < n; i++)
		cin >> data[i].first >> data[i].second;

	vector<int> dp(w + 1, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = w; j >= 0; j--)
		{
			if (j < data[i].first)
				continue;

			dp[j] = max(data[i].second + dp[j - data[i].first], dp[j]);
		}
	}

	cout << dp[w] << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
