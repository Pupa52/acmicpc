#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution()
{
	int n = 9;

	int sum = 0;

	vector<int> heights(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> heights[i];
		sum += heights[i];
	}

	sort(heights.begin(), heights.end());

	int result[2] = {};
	for (int i = 0; i < n - 1; i++)
	{
		int temp = sum - 100 - heights[i];
		for (int j = i + 1; j < n; j++)
		{
			if (temp == heights[j])
			{
				result[0] = i;
				result[1] = j;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (i == result[0] || i == result[1])
			continue;

		cout << heights[i] << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
