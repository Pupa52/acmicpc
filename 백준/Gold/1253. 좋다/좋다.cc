#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution()
{
	int answer = {};

	int n{};
	cin >> n;

	vector<int> arr(n);
	for (auto& iter : arr)
		cin >> iter;

	sort(arr.begin(), arr.end());

	int pt1, pt2;
	for (int i = 0; i < n; i++)
	{
		pt1 = 0;
		pt2 = n - 1;

		while (pt1 < pt2)
		{
			if (pt1 == i)
			{
				pt1++;
				continue;
			}
			if (pt2 == i)
			{
				pt2--;
				continue;
			}

			int temp = arr[pt1] + arr[pt2];
			if (temp > arr[i])
				pt2--;
			else if (temp < arr[i])
				pt1++;
			else if (temp == arr[i])
			{
				answer++;
				break;
			}
		}
	}

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
