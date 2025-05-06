#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	int t;
	cin >> t;

	int arr[30][30] = {};
	for (int i = 0; i < 30; i++)
		arr[1][i] = i;

	for (int i = 2; i < 30; i++)
		for (int j = i; j < 30; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i][j- 1];

		}

	while (t-- > 0)
	{
		int n, m;
		cin >> n >> m;

		cout << arr[n][m] << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
