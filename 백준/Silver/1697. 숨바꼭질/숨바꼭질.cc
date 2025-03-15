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
	int n, k;
	cin >> n >> k;

	vector<pair<bool, int>> visit(100'001, make_pair(false, 0));

	queue<int> q;
	q.push(n);
	visit[n].first = true;

	while (false == q.empty())
	{
		int index = q.front(); q.pop();
		if (index == k)
			break;

		int next = index * 2;
		if (next <= 100'000 && false == visit[next].first)
		{
			q.push(next);
			visit[next].first = true;
			visit[next].second = visit[index].second + 1;
		}

		next = index - 1;
		if (0 <= next && false == visit[next].first)
		{
			q.push(next);
			visit[next].first = true;
			visit[next].second = visit[index].second + 1;
		}

		next = index + 1;
		if (next <= 100'000 && false == visit[next].first)
		{
			q.push(next);
			visit[next].first = true;
			visit[next].second = visit[index].second + 1;
		}

	}//while (false == q.empty())

	cout << visit[k].second << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
