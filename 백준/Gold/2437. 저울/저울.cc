#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution()
{
	int n{};
	cin >> n;

	vector<int> arr(n, 0);
	for (auto& iter : arr)
		cin >> iter;

	sort(arr.begin(), arr.end());

	int range[2] = {};
	for (auto iter : arr)
	{
		if (iter > range[1] + 1)
		{
			cout << range[1] + 1;
			return;
		}

		else
		{
			range[1] += iter;
		}
	}

	cout << range[1] + 1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
