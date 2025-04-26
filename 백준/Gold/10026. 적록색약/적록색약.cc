#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int dfs(vector<string>& v, int n, char color)
{
	int Cnt = 0;

	stack<pair<int, int>> st;
	vector<vector<int>> visit(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == color && visit[i][j] == 0)
			{
				Cnt++;

				st.push(make_pair(i, j));
				visit[i][j] = 1;

				while (!st.empty())
				{
					auto value = st.top(); st.pop();

					for (int k = 0; k < 4; k++)
					{
						int x = value.first + dx[k];
						int y = value.second + dy[k];
						if ((x < 0 || n <= x) || (y < 0 || n <= y))
							continue;
						if (v[x][y] != color || visit[x][y] == 1)
							continue;

						st.push(make_pair(x, y));
						visit[x][y] = 1;
					}
				}
			}
		}
	}
	return Cnt;
}

void solution()
{
	int n;
	cin >> n;

	vector<string> v(n);
	for (auto& str : v)
		cin >> str;

	int RCnt = dfs(v, n, 'R');
	int GCnt = dfs(v, n, 'G');
	int BCnt = dfs(v, n, 'B');

	for (auto& str : v)
		for (auto& chr : str)
			chr = chr == 'G' ? 'R' : chr;

	int RGCnt = dfs(v, n, 'R');
	cout << RCnt + GCnt + BCnt << ' ';
	cout << RGCnt + BCnt << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}

