#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxDist = 100'000'001;

vector<pair<int, int>> edges[1'001];

void solution()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		edges[u].push_back({ w, v });
	}

	int st, en;
	cin >> st >> en;

	vector<int> dist(n + 1, maxDist);
	dist[st] = 0;

	vector<int> path(n + 1, 0);

	priority_queue<pair<int, int>> pq;
	pq.push({0, st});

	while (false == pq.empty())
	{
		pair<int, int> curr = pq.top(); pq.pop();
		if (curr.first != dist[curr.second])
			continue;

		for (auto& p : edges[curr.second])
		{
			if (dist[p.second] > curr.first + p.first)
			{
				dist[p.second] = curr.first + p.first;
				pq.push({ dist[p.second], p.second });
				path[p.second] = curr.second;
			}
		}
	}

	cout << dist[en] << '\n';

	vector<int> result;
	result.reserve(n + 1);

	for (int i = en; i != 0; i = path[i])
		result.push_back(i);

	cout << result.size() << '\n';
	for(auto iter = result.rbegin(); iter != result.rend(); iter++)
		cout << *iter << ' ';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
