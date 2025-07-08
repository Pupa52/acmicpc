#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	vector<int> v(10'000 + 1, 0);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		v[temp]++;
	}

	int result = 0;
	int total = INT_MAX;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 0)
			continue;

		int temp = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] == 0)
				continue;

			temp += abs(j - i) * v[j];
		}

		if (temp < total)
		{
			result = i;
			total = temp;
		}
	}

	cout << result << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
