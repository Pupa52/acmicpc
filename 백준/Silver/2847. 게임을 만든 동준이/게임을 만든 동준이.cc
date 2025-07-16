#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];

	int cnt = 0;
	for (int i = n - 1; i > 0; --i)
	{
		if (v[i] > v[i + 1] - 1)
		{
			cnt += v[i] - (v[i + 1] - 1);
			v[i] = v[i + 1] - 1;
		}
	}
	cout << cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
