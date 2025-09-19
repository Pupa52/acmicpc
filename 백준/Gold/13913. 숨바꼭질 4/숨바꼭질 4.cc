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
	vector<int> path(100'001, 0);
	queue<int> q;

	visit[n] = 0;
	path[n] = -1;
	q.push(n);

	while (false == q.empty())
	{
		int curr = q.front(); q.pop();
		if (curr == k)
			break;

		int next[] = { curr - 1, curr + 1, curr * 2 };
		for (int i = 0; i < 3; i++)
		{
			if (next[i] < 0 || 100'000 < next[i])
				continue;

			if (visit[next[i]] != INT_MAX)
				continue;

			visit[next[i]] = visit[curr] + 1;
			path[next[i]] = curr;
			q.push(next[i]);
		}
	}

	cout << visit[k] << '\n';

	vector<int> result;
	result.push_back(k);
	for (int i = k; path[i] != -1; i = path[i])
		result.push_back(path[i]);

	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << ' ';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
