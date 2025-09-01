#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxDist = 1'000'000'001;

vector<pair<int, int>> edges[10'001];

void solution()
{
	int n{}, m{};
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a{}, b{}, c{};
		cin >> a >> b >> c;

		edges[a].push_back({ c, b });
		edges[b].push_back({ c, a });
	}

	int st{}, en{};
	cin >> st >> en;

	vector<int> dist(n + 1, -1);
	priority_queue<pair<int, int>> pq;

	dist[st] = maxDist;
	pq.push({ dist[st], st });

	while (false == pq.empty())
	{
		pair<int, int> curr = pq.top(); pq.pop();
		if (curr.first != dist[curr.second])
			continue;

		for (auto& p : edges[curr.second])
		{
			if (dist[p.second] < min(curr.first, p.first))
			{
				dist[p.second] = min(curr.first, p.first);
				pq.push({ dist[p.second], p.second });
			}
		}
	}

	cout << dist[en];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
