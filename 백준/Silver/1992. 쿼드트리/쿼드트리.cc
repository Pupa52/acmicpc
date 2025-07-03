#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void dfs(vector<vector<int>>& graph, int stX, int stY, int width)
{
	cout << '(';

	int dx[] = { stX, stX + width, stX, stX + width };
	int dy[] = { stY, stY, stY + width, stY + width };

	// 0
	for (int i = 0; i < 4; i++)
	{
		int sum = 0;
		for (int j = dy[i]; j < dy[i] + width; j++)
			for (int k = dx[i]; k < dx[i] + width; k++)
				sum += graph[j][k];

		if (sum == 0 || sum == (width * width))
			cout << sum / (width * width);
		else
			dfs(graph, dx[i], dy[i], width / 2);
	}

	cout << ')';
}

void solution()
{
	int n;
	cin >> n;

	vector<vector<int>> graph(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char chr;
			cin >> chr;

			graph[i][j] = chr - '0';
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sum += graph[i][j];

	if (sum == 0 || sum == (n*n))
		cout << sum / (n * n);
	else
		dfs(graph, 0, 0, n / 2);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
