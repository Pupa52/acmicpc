#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

void solution()
{
	int n;
	cin >> n;
	
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	while (n-- > 0)
	{
		int x;
		cin >> x;

		if (0 == x)
		{
			if (pq.empty())
				cout << 0 << endl;
			else
			{
				pii value = pq.top(); pq.pop();
				cout << value.second << endl;
			}
		}

		else
		{
			pq.push(make_pair(abs(x), x));
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
