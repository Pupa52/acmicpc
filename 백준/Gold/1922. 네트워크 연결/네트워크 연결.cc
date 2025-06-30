#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>

using namespace std;

bool compare(const tuple<int, int, int>& lhs, const tuple<int, int, int>& rhs)
{
	return get<2>(lhs) < get<2>(rhs);
}

int Find(vector<int>& parents, int element)
{
	int i = element;
	
	for (; i != parents[i]; i = parents[i]);

	parents[element] = i;

	return i;
}

void Union(vector<int>& parents, int a, int b)
{
	parents[Find(parents, a)] = Find(parents, b);
}

void solution()
{
	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int>> lines(m);
	for (int i = 0; i < m; i++)
		cin >> get<0>(lines[i]) >> get<1>(lines[i]) >> get<2>(lines[i]);

	sort(lines.begin(), lines.end(), compare);

	vector<int> parents(n + 1);
	iota(parents.begin(), parents.end(), 0);
	
	int total = 0;
	for (int i = 0; i < m; i++)
	{
		int u = min(get<0>(lines[i]), get<1>(lines[i]));
		int v = max(get<0>(lines[i]), get<1>(lines[i]));

		if (Find(parents, u) != Find(parents, v))
		{
			Union(parents, u, v);
			total += get<2>(lines[i]);
		}
	}

	cout << total << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
