#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int bfs(vector<vector<int>>& graph, int x, int y, int height, int width)
{
	int result = 0;

	queue<pii> q;

	graph[y][x] = 1;
	q.push(make_pair(y, x));
	result += 1;

	while (false == q.empty())
	{
		auto curr = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curr.second + dx[i];
			int nextY = curr.first + dy[i];

			if ((nextX < 0 || width <= nextX) || (nextY < 0 || height <= nextY))
				continue;

			if (graph[nextY][nextX] != 0)
				continue;

			graph[nextY][nextX] = 1;
			q.push(make_pair(nextY, nextX));
			result += 1;
		}
	}

	return result;
}

void solution()
{
	int m, n, t;
	cin >> m >> n >> t;

	vector<vector<int>> graph(m, vector<int>(n, 0));

	for (int i = 0; i < t; i++)
	{
		int x1, y1;
		int x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++) 
			for (int k = x1; k < x2; k++)
				graph[j][k] = 2;
	}

	vector<int> result;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 0)
			{
				int ret = bfs(graph, j, i, m, n);
				result.push_back(ret);
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << '\n';
	for (auto iter : result)
		cout << iter << ' ';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
