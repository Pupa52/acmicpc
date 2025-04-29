#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	vector<vector<int>> graph(n, vector<int>(n, 0));
	for (auto& row : graph)
		for (auto& col : row)
			cin >> col;

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (graph[i][j] == 1)
					continue;
				if (graph[i][k] == 0 || graph[k][j] == 0)
					continue;

				graph[i][j] = 1;
			}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << graph[i][j];
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
