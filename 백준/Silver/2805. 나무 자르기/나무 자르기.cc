#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solution()
{
	int n, m, result = 0;
	cin >> n >> m;

	vector<int> trees(n);
	for (auto& iter : trees)
		cin >> iter;

	ll start = 1, end = 0x7fff'ffff;
	while (start < end)
	{
		ll mid = (start + end) / 2LL;

		ll sum = 0;
		for (auto& iter : trees)
			sum += (iter - mid) > 0 ? (iter - mid) : 0;

		if (sum >= m)
		{
			start = mid + 1;
			result = (int)mid;
		}
		else
			end = mid;
	}

	cout << result << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
