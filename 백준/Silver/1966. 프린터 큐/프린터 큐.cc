#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;

void solution()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n, m;
		cin >> n >> m;

		vector<pii> v(n);
		for (auto& p : v)
			cin >> p.first;

		int outCnt = 1;
		int front = 0;
		int offset = 0;
		for (int i = 9; i > 0; i--)
		{
			offset = front;
			for (int j = 0; j < n; j++)
			{
				int index = (j + offset) % n;
				if (v[index].first == i)
				{
					v[index].second = outCnt++;
					front = index;
				}
			}
		}

		cout << v[m].second << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
