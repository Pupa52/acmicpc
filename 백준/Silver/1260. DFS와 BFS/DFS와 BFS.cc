#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& graph, int n, int m, int v)
{
	vector<int> visit(n + 1, 0);
	stack<int> st;

	st.push(v);
	while (!st.empty())
	{
		int value = st.top(); st.pop();
		if (visit[value] == 1)
			continue;

		visit[value] = 1;

		cout << value << ' ';

		for (int i = n; i > 0; i--)
		{
			if (1 != visit[i] && graph[value][i])
			{
				st.push(i);
			}
		}
	}
}

void bfs(vector<vector<int>>& graph, int n, int m, int v)
{
	vector<int> visit(n + 1, 0);
	queue<int> q;

	q.push(v);
	visit[v] = 1;
	cout << v << ' ';

	while (!q.empty())
	{
		int value = q.front(); q.pop();
		for (int i = 0; i <= n; i++)
		{
			if (1 != visit[i] && 1 == graph[value][i])
			{
				q.push(i);
				visit[i] = 1;
				cout << i << ' ';
			}
		}
	}
}

void solution()
{
	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u][v] = graph[v][u] = 1;
	}

	dfs(graph, n, m, v);
	cout << '\n';
	bfs(graph, n, m, v);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
