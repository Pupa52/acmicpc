#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

void solution()
{
	int t;
	cin >> t;

	while (t--)
	{
		int h, w, n;
		cin >> h >> w >> n;

		int i = (n - 1) / h + 1;
		int j = (n - 1) % h + 1;

		if (i < 10)
			cout << j << '0' << i << endl;
		else
			cout << j << i << endl;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
