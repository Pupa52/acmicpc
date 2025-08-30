#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxDist = 3'001;

vector<pair<int, int>> adj[101];

int dijkstra(int n, int m, int st, vector<int>& items)
{
	int result = 0;

	vector<int> dist(n + 1, maxDist);
	queue<pair<int, int>> q;

	dist[st] = 0;
	q.push({0, st});

	while (false == q.empty())
	{
		auto curr = q.front(); q.pop();

		for (auto& p : adj[curr.second])
		{
			if (dist[p.second] > curr.first + p.first)
			{
				dist[p.second] = curr.first + p.first;
				q.push({ dist[p.second], p.second });
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] <= m)
			result += items[i];
	}
	return result;
}

void solution()
{
	int n, m, r;
	cin >> n >> m >> r;

	vector<int> items(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> items[i];

	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;

		adj[a].push_back({ l, b });
		adj[b].push_back({ l, a });
	}

	int answer = 0;
	for (int i = 1; i <= n; i++)
		answer = max(answer, dijkstra(n, m, i, items));

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
