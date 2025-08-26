#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;

int Find(vector<int>& parents, int element) {
	int i = element;
	for (; i != parents[i]; i = parents[i]);

	parents[element] = i;

	return i;
}

void Union(vector<int>& parents, int i, int j) {
	parents[Find(parents, j)] = Find(parents, i);
}

void solution()
{
	int n, m;
	cin >> n >> m;

	vector<int> parents(n + 1);
	for (int i = 0; i < parents.size(); i++)
		parents[i] = i;


	for (int i = 0; i < m; i++)
	{
		int cmd, a, b;
		cin >> cmd >> a >> b;

		if (a > b)
			swap(a, b);

		switch (cmd)
		{
		case 0:
			Union(parents, a, b);
			break;

		case 1:
			if (Find(parents, a) == Find(parents, b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
			break;
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
