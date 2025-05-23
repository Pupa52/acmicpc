#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

using ll = long long;

ll MyAbs(ll number)
{
	return number < 0 ? number * -1 : number;
}

void solution()
{
	int n;
	cin >> n;

	vector<int> data(n);
	for (int i = 0; i < n; i++)
		cin >> data[i];

	sort(data.begin(), data.end());

	ll minValue = LONG_MAX;
	vector<int> result(3);

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			ll total = (ll)data[i] + data[j];
			
			int st = j + 1, en = n;
			while (st != en)
			{
				int mid = (st + en) / 2;
				ll temp = total + data[mid];

				if (MyAbs(temp) < MyAbs(minValue))
				{
					minValue = temp;
					result[0] = data[i];
					result[1] = data[j];
					result[2] = data[mid];
				}

				if (temp < 0)
					st = mid + 1;
				else
					en = mid;
			}
		}
	}

	for (auto iter : result)
		cout << iter << ' ';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
