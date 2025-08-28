#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxDist = 500'001;

vector<int> edges[101];

void solution()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	int minValue = maxDist;
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		vector<int> dist(n + 1, maxDist);
		dist[i] = 0;

		priority_queue<int> pq;
		pq.push(i);

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

		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += dist[i];
		if (sum < minValue)
		{
			minValue = sum;
			answer = i;
		}
	}

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
