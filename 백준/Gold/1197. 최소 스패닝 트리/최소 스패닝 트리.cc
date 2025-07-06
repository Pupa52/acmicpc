#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct weight {
	int u;
	int v;
	int w;
};

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
	int v, e;
	cin >> v >> e;
	
	vector<weight> edges(e);
	for (int i = 0; i < e; i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].w;

	sort(edges.begin(), edges.end(), [](const weight& lhs, const weight& rhs) {
		return lhs.w < rhs.w;
		});

	vector<int> parents(v + 1);
	for (int i = 0; i < v; i++)
		parents[i] = i;

	long long total = 0;
	for (int i = 0; i < e; i++)
	{
		int u = min(edges[i].u, edges[i].v);
		int v = max(edges[i].u, edges[i].v);

		if (Find(parents, u) != Find(parents, v))
		{
			Union(parents, u, v);
			total += edges[i].w;
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
