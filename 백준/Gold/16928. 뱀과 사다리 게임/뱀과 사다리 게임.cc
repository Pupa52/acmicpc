#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solution()
{
	int n, m;
	cin >> n >> m;

	vector<int> board(101, 0);

	for (int i = 0; i < n + m; i++)
	{
		int x, y;
		cin >> x >> y;

		board[x] = y;
	}

	vector<int> visit(101, 30'000);
	queue<int> q;

	q.push(1);
	visit[1] = 0;

	while (false == q.empty())
	{
		int value = q.front(); q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int next = value + i;

			if (100 < next)
				continue;

			if (0 != board[next])
				next = board[next];

			if (visit[value] + 1 >= visit[next])
				continue;

			q.push(next);
			visit[next] = visit[value] + 1;
		}
	}

	cout << visit.back() << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
