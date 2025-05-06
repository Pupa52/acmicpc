#include <iostream>
#include <vector>

#define INF 0x3fff'ffff

using namespace std;

void solution()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n, vector<int>(n, INF));
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		graph[u - 1][v - 1] = min(graph[u - 1][v - 1], w);
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					continue;

				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << (graph[i][j] == INF ? 0 : graph[i][j]);
			if (j + 1 < n)
				cout << ' ';
		}
		cout << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
