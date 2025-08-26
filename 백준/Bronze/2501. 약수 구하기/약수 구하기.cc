#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	int n, k;
	cin >> n >> k;

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int mod = n % i;
		if (mod == 0)
		{
			cnt++;
			if (cnt == k)
			{
				cout << i;
				return;
			}
		}
	}

	cout << 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
