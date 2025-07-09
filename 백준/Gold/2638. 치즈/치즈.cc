#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int bfs(vector<int>& graph, int n, int m)
{
	vector<int> visit(graph.size());
	queue<int> q;

	visit[0] = 1;
	q.push(0);

	int ret = 0;
	while (false == q.empty())
	{
		int curr = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = curr % m + dx[i];
			int y = curr / m + dy[i];
			int next = y * m + x;

			if (x < 0 || m <= x || y < 0 || n <= y)
				continue;

			if (visit[next] != 0)
			{
				if (graph[next] == 1)
				{
					graph[next] = 0;
					ret++;
				}

				continue;
			}

			visit[next] = 1;
			if (graph[next] == 0)
				q.push(next);
		}
	}

	return ret;
}

void solution()
{
	int n, m;
	cin >> n >> m;

	vector<int> graph(n * m);
	int total = 0;

	for (int i = 0; i < graph.size(); i++)
	{
		cin >> graph[i];
		total = graph[i] == 1 ? total + 1 : total;
	}

	int Cnt = 0;
	while (total != 0)
	{
		int ret = bfs(graph, n, m);
		total -= ret;
		Cnt++;
	}

	cout << Cnt << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
