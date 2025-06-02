#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

void solution()
{
	int n, m;
	cin >> n >> m;

	vector<ll> arr(n), result;
	result.reserve(m);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	for (int i = 0; i < m; i++)
	{
		ll cmd, first, second;
		cin >> cmd;

		if (cmd == 1)
		{
			cin >> first;
			auto lower = lower_bound(arr.begin(), arr.end(), first);
			result.push_back(arr.end() - lower);
		}

		else if (cmd == 2)
		{
			cin >> first;
			auto upper = upper_bound(arr.begin(), arr.end(), first);
			result.push_back(arr.end() - upper);
		}

		else if (cmd == 3)
		{
			cin >> first >> second;
			auto lower = lower_bound(arr.begin(), arr.end(), first);
			auto upper = upper_bound(arr.begin(), arr.end(), second);
			result.push_back(upper - lower);
		}
	}

	for (auto iter : result)
		cout << iter << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
