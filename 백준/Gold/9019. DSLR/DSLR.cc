#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void solution()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int a, b;
		cin >> a >> b;

		vector<string> visit(10'000, "");
		queue<int> q;

		visit[a] = "N";
		q.push(a);

		while (false == q.empty())
		{
			int curr = q.front(); q.pop();
			if (curr == b)
			{
				for (auto chr : visit[curr])
				{
					if (chr == 'N')
						continue;
					cout << chr;
				}
				cout << '\n';
				break;
			}

			// D
			int next = (curr * 2) % 10'000;
			if (visit[next] == "")
			{
				visit[next] = visit[curr];
				visit[next].push_back('D');
				q.push(next);
			}

			// S
			next = curr == 0 ? 9999 : curr - 1;
			if (visit[next] == "")
			{
				visit[next] = visit[curr];
				visit[next].push_back('S');
				q.push(next);
			}

			// L
			next = (curr / 1000) + (curr % 1000) * 10;
			if (visit[next] == "")
			{
				visit[next] = visit[curr];
				visit[next].push_back('L');
				q.push(next);
			}

			// R
			next = (curr / 10) + (curr % 10) * 1000;
			if (visit[next] == "")
			{
				visit[next]= visit[curr];
				visit[next].push_back('R');
				q.push(next);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
