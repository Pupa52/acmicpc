#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxDist = 300'001;

vector<int> edges[300'001];

void solution()
{
	int n, m, k, x;
	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		edges[u].push_back(v);
	}

	vector<int> dist(n + 1, maxDist);
	dist[x] = 0;

	priority_queue<int> pq;
	pq.push(x);

	while (false == pq.empty())
	{
		int curr = pq.top(); pq.pop();

		for (auto iter : edges[curr])
		{
			if (dist[iter] > dist[curr] + 1)
			{
				dist[iter] = dist[curr] + 1;
				pq.push(iter);
			}
		}
	}

	vector<int> result;
	for (int i = 1; i <= n; i++)
		if (dist[i] == k)
			result.push_back(i);

	if (result.empty())
		cout << -1;
	else
	{
		for (auto iter : result)
			cout << iter << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
