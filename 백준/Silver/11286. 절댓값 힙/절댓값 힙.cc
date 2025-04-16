#include <iostream>
#include <queue>

using namespace std;

struct _cmp {
	bool operator()(int lhs, int rhs) {
		if (abs(lhs) != abs(rhs))
			return abs(lhs) > abs(rhs);
		return lhs > rhs;
	}
};

void solution()
{
	int n;
	cin >> n;
	
	priority_queue<int, vector<int>, _cmp> pq;

	while (n-- > 0)
	{
		int x;
		cin >> x;

		if (0 == x)
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}

		else
			pq.push(x);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
