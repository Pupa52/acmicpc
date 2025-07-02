#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void solution()
{
	int n, k;
	cin >> n >> k;

	vector<int> visit(100'001, INT_MAX);
	queue<int> q;

	visit[n] = 0;
	q.push(n);

	int Cnt = 0;

	auto f = [&](int curr, int next) {
		if (next < 0 || 100'000 < next)
			return;

		if (visit[next] >= visit[curr] + 1)
		{
			visit[next] = visit[curr] + 1;
			q.push(next);
		}
	};

	while (false == q.empty())
	{
		int curr = q.front(); q.pop();
		if (curr == k)
			Cnt++;

		int next = curr - 1;
		f(curr, next);

		next = curr + 1;
		f(curr, next);

		next = curr * 2;
		f(curr, next);
	}

	cout << visit[k] << '\n';
	cout << Cnt << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
