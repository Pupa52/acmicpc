#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

const int maxDist = 10'001;

void solution()
{
	int n{}, m{};
	cin >> n >> m;

	vector<string> graph(m);
	for (auto& str : graph)
		cin >> str;

	vector<int> dist(m * n, maxDist);
	queue<pair<int, int>> q;

	dist[0] = 0;
	q.push({ dist[0], 0 });

	while (false == q.empty())
	{
		auto curr = q.front(); q.pop();
		if (curr.first != dist[curr.second])
			continue;

		for (int i = 0; i < 4; i++)
		{
			int x = curr.second % n + dx[i];
			int y = curr.second / n + dy[i];
			if (!(0 <= x && x < n && 0 <= y && y < m))
				continue;

			int next = y * n + x;
			int weight = curr.first;
			if (graph[y][x] == '1')
				weight += 1;

			if (dist[next] > weight)
			{
				dist[next] = weight;
				q.push({ dist[next], next });
			}
		}
	}

	cout << dist.back();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
