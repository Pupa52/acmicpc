#include <iostream>
#include <vector>
#include <cmath>

typedef struct _rgb {
	int r;
	int g;
	int b;
}RGB;

using namespace std;

void solution()
{
	int n;
	cin >> n;

	vector<RGB> cost(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> cost[i].r >> cost[i].g >> cost[i].b;

	vector<RGB> v(n + 1);
	v[1] = cost[1];

	for (int i = 2; i <= n; i++)
	{
		v[i].r = min(v[i - 1].g, v[i - 1].b) + cost[i].r;
		v[i].g = min(v[i - 1].r, v[i - 1].b) + cost[i].g;
		v[i].b = min(v[i - 1].r, v[i - 1].g) + cost[i].b;
	}

	if (v[n].r > v[n].g)
		swap(v[n].r, v[n].g);
	if (v[n].r > v[n].b)
		swap(v[n].r, v[n].b);

	cout << v[n].r << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
