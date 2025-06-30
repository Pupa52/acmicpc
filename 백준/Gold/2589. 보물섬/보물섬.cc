#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int bfs(vector<string>& map, int width, int height, pair<int, int> pos)
{
	vector<int> visit(width * height, -1);
	queue<pair<int, int>> q;

	visit[pos.first * width + pos.second] = 0;
	q.push(pos);

	int ret = 0;

	while (false == q.empty())
	{
		auto curr = q.front(); q.pop();
		int index = curr.first * width + curr.second;

		for (int i = 0; i < 4; i++)
		{
			int x = curr.second + dx[i];
			int y = curr.first + dy[i];

			if ((x < 0 || width <= x) || (y < 0 || height <= y))
				continue;

			int next = y * width + x;
			if (map[y][x] == 'W' || visit[next] >= 0)
				continue;

			visit[next] = visit[index] + 1;
			q.push(make_pair(y, x));

			ret = max(ret, visit[next]);
		}
	}

	return ret;
}

void solution()
{
	int width, height;
	cin >> height >> width;

	vector<string> map(height);
	for (int i = 0; i < height; i++)
		cin >> map[i];

	int result = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] == 'W')
				continue;

			int ret = bfs(map, width, height, make_pair(i, j));
			result = max(ret, result);
		}
	}

	cout << result << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
