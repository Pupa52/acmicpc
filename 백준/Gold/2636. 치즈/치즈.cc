#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using pii = pair<int, int>;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int bfs(vector<vector<int>>& graph, int row, int col)
{
	int Cnt = 0;

	queue<pii> q;
	vector<vector<int>> visit(row, vector<int>(col, 0));

	q.push({ 0, 0 });
	visit[0][0] = 1;

	while (false == q.empty())
	{
		auto curr = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int x = curr.second + dx[i];
			int y = curr.first + dy[i];

			if ((x < 0 || col <= x) || (y < 0 || row <= y))
				continue;

			if (visit[y][x] == 1)
				continue;

			if (graph[y][x] == 0)
				q.push({ y, x });

			else
			{
				graph[y][x] = 0;
				Cnt++;
			}
			visit[y][x] = 1;
		}
	}

	return Cnt;
}

void solution()
{
	int n, m;
	cin >> n >> m;

	int Cnt = 0;

	vector<vector<int>> cheese(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> cheese[i][j];
			if (cheese[i][j] == 1)
				Cnt++;
		}
	}

	int time = 0;

	while (true)
	{
		int ret = bfs(cheese, n, m);
		time++;

		if ((Cnt - ret) == 0)
			break;

		Cnt -= ret;
	}

	cout << time << '\n' << Cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
