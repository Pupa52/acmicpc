#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

void solution()
{
	int t;
	cin >> t;

	int arr[15][14] = { 0, };
	for (int i = 0; i < 14; i++)
		arr[0][i] = i + 1;

	for (int i = 1; i <= 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			int sum = 0;
			for (int k = 0; k <= j; k++)
				sum += arr[i - 1][k];
			arr[i][j] = sum;
		}
	}

	while (t-- > 0)
	{
		int k, n;
		cin >> k >> n;

		cout << arr[k][n - 1] << endl;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
