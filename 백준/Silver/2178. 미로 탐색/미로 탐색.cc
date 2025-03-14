#include <iostream>
#include <string>

#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <algorithm>
#include <memory>

#include <cstring>

using namespace std;

pair<int, int> offsets[4] = {
	{-1,  0 },
	{ 1,  0},
	{ 0, -1},
	{ 0,  1}
};

bool InBound(int row, int col, int width, int height)
{
	return (0 <= row && row < height) && (0 <= col && col < width);
}

void solution()
{
	int n{}, m{};
	cin >> n >> m;

	queue<int> q;
	vector<int> maze, visit;
	maze.resize(n * m, 0);
	visit.resize(n * m, 0);

	for (int i = 0; i < n; i++)
	{
		char input[101] = {};
		cin >> input;

		for (int j = 0; j < m; j++)
			maze[i * m + j] = input[j] - '0';
	}

	q.push(0); // (1,1)
	while (false == q.empty())
	{
		int index = q.front(); q.pop();

		if (index == maze.size() - 1)
			break;
		if (1 == visit[index])
			continue;

		visit[index] = 1;

		for (int i = 0; i < 4; i++)
		{
			int row = index / m + offsets[i].first;
			int col = index % m + offsets[i].second;
			int next = row * m + col;

			if (false == InBound(row, col, m, n) || 0 == maze[next])
				continue;

			maze[next] = maze[index] + 1;
			q.push(next);
		}
	}

	cout << maze.back() << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
