#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edges[100'001];

void solution()
{
	int n{}, k{};
	cin >> n >> k;

	for (int i = 0; i < n - 1; i++)
	{
		int p{}, c{};
		cin >> p >> c;

		edges[p].push_back(c);
	}

	vector<int> apple(n);
	for (auto& iter : apple)
		cin >> iter;

	vector<int> visit(n, -1);
	queue<int> q;

	visit[0] = 0;
	q.push(0);

	int answer = 0;
	while (false == q.empty())
	{
		int curr = q.front(); q.pop();
		answer += apple[curr];

		if (visit[curr] == k)
			continue;

		for (auto iter : edges[curr])
		{
			if (visit[iter] == -1)
			{
				visit[iter] = visit[curr] + 1;
				q.push(iter);
			}
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
