#include <iostream>
#include <vector>
#include <queue>

constexpr int INF = 0x5fff'ffff;

using namespace std;
using pii = pair<int, int>;

vector<pii> edges[200001];

void solution()
{
	int v, e, k;
	cin >> v >> e >> k;

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		edges[u].push_back({w, v});
	}

	vector<int> dist(v + 1, INF);
	dist[k] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, k });

	while (false == pq.empty())
	{
		pii edge = pq.top(); pq.pop();
		int index = edge.second;
		int weight = edge.first;

		if (weight != dist[index])
			continue;

		for (auto& p : edges[edge.second])
		{
			if (weight + p.first < dist[p.second])
			{
				dist[p.second] = weight + p.first;
				pq.push({ dist[p.second], p.second});
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << endl;
		else
			cout << dist[i] << endl;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
