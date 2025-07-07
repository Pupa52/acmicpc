#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solution()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1);
	vector<int> indegree(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		indegree[v] += 1;
	}

	queue<int> q;
	for (int i = 0; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);

	vector<int> result;
	while (false == q.empty())
	{
		int curr = q.front(); q.pop();

		result.push_back(curr);

		for (auto iter : adj[curr])
		{
			indegree[iter] -= 1;
			if (indegree[iter] == 0)
				q.push(iter);
		}
	}

	for (int i = 1; i < result.size(); i++)
		cout << result[i] << ' ';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
