#include <iostream>
#include <vector>

#include <climits>

using namespace std;

constexpr int MAX = 0x5fff'ffff;

int choose(vector<int>& dist, vector<int>& found)
{
	int index = -1, min = MAX;
	for (int i = 0; i < dist.size(); i++)
	{
		if (0 == found[i] && dist[i] < min)
		{
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(vector<vector<int>>& cities, vector<int>& dist, int n, int x)
{
	vector<int> found(n, 0);
	for (int i = 0; i < n; i++)
	{
		cities[i][i] = 0;
		dist[i] = cities[x - 1][i];
	}

	found[x - 1] = 1;
	for (int i = 0; i < n - 2; i++)
	{
		int min = choose(dist, found);
		found[min] = 1;

		for (int j = 0; j < n; j++)
		{
			if (1 == found[j])
				continue;
			if (dist[min] + cities[min][j] < dist[j])
				dist[j] = dist[min] + cities[min][j];
		}

	}
}

void solution()
{
	int n, m, x;
	cin >> n >> m >> x;

	vector<vector<int>> cities0(n, vector<int>(n, MAX));
	vector<vector<int>> cities1(n, vector<int>(n, MAX));
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		cities0[u - 1][v - 1] = w;
		cities1[v - 1][u - 1] = w;
	}

	vector<int> dist0(n), dist1(n);
	dijkstra(cities0, dist0, n, x);
	dijkstra(cities1, dist1, n, x);

	int max = 0;
	for (int i = 0; i < n; i++)
		max = (dist0[i] + dist1[i]) > max ? (dist0[i] + dist1[i]) : max;
	cout << max << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
