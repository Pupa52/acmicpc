#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void solution()
{
	int n{}, m{};
	cin >> n >> m;

	vector<string> graph(n);
	for (auto& str : graph)
		cin >> str;

	vector<int> visit(n * m, 0);
	queue<int> q;

	visit[0] = 1;
	q.push(0);

	while (false == q.empty())
	{
		int curr = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = curr % m + dx[i];
			int y = curr / m + dy[i];

			if (!(0 <= x && x < m && 0 <= y && y < n))
				continue;

			if (graph[y][x] == '0')
				continue;

			int next = y * m + x;
			if (visit[next] != 0)
				continue;

			visit[next] = visit[curr] + 1;
			q.push(next);
		}
	}

	cout << visit.back();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
