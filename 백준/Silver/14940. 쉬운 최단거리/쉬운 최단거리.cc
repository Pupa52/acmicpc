#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void solution()
{
	int n, m;
	cin >> n >> m;

	queue<pair<int, int>> q;

	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<vector<int>> visit(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				q.push({ i, j });
				visit[i][j] = 0;
			}
			else if (map[i][j] == 0)
				visit[i][j] = 0;
		}

	while (!q.empty())
	{
		pair<int, int> value = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = value.first + dx[i];
			int y = value.second + dy[i];
			if (x < 0 || n <= x || y < 0 || m <= y)
				continue;
			if (visit[x][y] != -1)
				continue;

			q.push({ x, y });
			visit[x][y] = visit[value.first][value.second] + 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << visit[i][j];
			if (j + 1 < m)
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

