#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solution()
{
	int m, n, result = 0;
	cin >> m >> n;

	vector<int> cookies(n, 0);
	for (auto& iter : cookies)
		cin >> iter;

	sort(cookies.begin(), cookies.end(), less<int>());

	ll start = 1, middle, end = cookies.back() * 2LL;
	while (start < end)
	{
		middle = (start + end) / 2;
		
		ll count = 0;
		for (auto& iter : cookies)
			count += iter / middle;

		if (count >= m)
		{
			start = middle + 1;
			result = (int)middle;
		}
		else
			end = middle;
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
