#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int ofsX[4] = {-1, 0, 1, 0};
int ofsY[4] = { 0, 1, 0, -1 };

void solution()
{
	int n, count = 0;
	cin >> n;

	vector<string> graph(n);
	vector<int> houses;
	for (auto& str : graph)
		cin >> str;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ('1' == graph[i][j])
			{
				count++;

				stack<pii> st;
				st.push(make_pair(i, j));
				graph[i][j] = '0';

				int houseCnt = 0;
				while (!st.empty())
				{
					pii value = st.top(); st.pop();
					houseCnt++;
					for (int i = 0; i < 4; i++)
					{
						int x = value.first + ofsX[i];
						int y = value.second + ofsY[i];
						if (x < 0 || n <= x || y < 0 || n <= y)
							continue;
						if (graph[x][y] == '1')
						{
							st.push(make_pair(x, y));
							graph[x][y] = '0';
						}
					}
				}
				houses.push_back(houseCnt);
			}
		}
	}

	cout << count << '\n';

	sort(houses.begin(), houses.end());

	for (auto& iter : houses)
		cout << iter << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
