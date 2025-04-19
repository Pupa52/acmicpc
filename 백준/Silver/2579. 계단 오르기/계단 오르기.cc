#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	vector<int> weights(n, 0);
	for (auto& iter : weights)
		cin >> iter;

	if (n == 1)
	{
		cout << weights[0] << endl;
		return;
	}

	vector<vector<int>> dist(n, vector<int>(2, 0));
	dist[0][0] = dist[0][1] = weights[0];
	dist[1][0] = weights[1];
	dist[1][1] = dist[0][1] + weights[1];

	for (int i = 2; i < n; i++)
	{
		dist[i][0] = max(dist[i - 2][0], dist[i - 2][1]) + weights[i];
		dist[i][1] = dist[i - 1][0] + weights[i];
	}

	cout << (dist[n - 1][0] > dist[n - 1][1] ? dist[n - 1][0] : dist[n - 1][1]) << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
