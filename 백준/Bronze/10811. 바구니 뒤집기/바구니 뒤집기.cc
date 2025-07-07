#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solution()
{
	int n, m;
	cin >> n >> m;

	vector<int> arr(n + 1);
	iota(arr.begin(), arr.end(), 0);

	for (int i = 0; i < m; i++)
	{
		int st, en;
		cin >> st >> en;

		int index = (en - st + 1) / 2;
		for (int j = 0; j < index; j++)
			swap(arr[st++], arr[en--]);
	}

	for (int i = 1; i <= n; i++)
		cout << arr[i] << ' ';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
