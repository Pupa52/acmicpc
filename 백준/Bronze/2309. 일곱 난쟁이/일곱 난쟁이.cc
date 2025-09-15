#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution()
{
	int sum = 0;

	vector<int> arr(9);
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr.begin(), arr.end());

	int answer[2] = {};
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - arr[i] - arr[j] == 100)
			{
				answer[0] = i;
				answer[1] = j;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (i == answer[0] || i == answer[1])
			continue;

		cout << arr[i] << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
