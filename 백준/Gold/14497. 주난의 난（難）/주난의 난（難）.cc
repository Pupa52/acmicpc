#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point {
	int x;
	int y;
};

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool bfs(vector<char>& graph, int n, int m, point st, point en)
{
	vector<int> visit(graph.size(), 0);
	queue<int> q;

	int index = st.y * m + st.x;
	visit[index] = 1;
	q.push(index);

	while (false == q.empty())
	{
		int curr = q.front(); q.pop();
		if ((curr % m == en.x) && (curr / m == en.y))
			return true;

		for (int i = 0; i < 4; i++)
		{
			int x = curr % m + dx[i];
			int y = curr / m + dy[i];
			int next = y * m + x;

			if ((x < 0 || m <= x) || (y < 0 || n <= y))
				continue;

			if (visit[next] != 0)
				continue;

			visit[next] = 1;
			if (graph[next] == '1')
				graph[next] = '0';
			else
				q.push(next);
		}
	}

	return false;
}

void solution()
{
	int n, m;
	cin >> n >> m;

	struct point st, en;
	cin >> st.y >> st.x;
	cin >> en.y >> en.x;

	vector<char> graph(n * m);
	for (int i = 0; i < n * m; i++)
		cin >> graph[i];

	st.x -= 1;
	st.y -= 1;
	en.x -= 1;
	en.y -= 1;

	int Cnt = 0;
	while (true)
	{
		Cnt++;
		if (true == bfs(graph, n, m, st, en))
			break;
	}

	cout << Cnt << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
