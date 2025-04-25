#include <iostream>
#include <vector>

using namespace std;

void rec(vector<vector<int>>& v, int x, int y, int n, int& white, int& blue)
{
	int sum = 0;
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			sum += v[i][j];

	if (sum == 0)
		white += 1;
	else if (sum == n * n)
		blue += 1;
	else
	{
		int next = n / 2;
		rec(v, x, y, next, white, blue);
		rec(v, x + next, y, next, white, blue);
		rec(v, x, y + next, next, white, blue);
		rec(v, x + next, y + next, next, white, blue);
	}
}

void solution()
{
	int n;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];

	int white{}, blue{};
	rec(v, 0, 0, n, white, blue);

	cout << white << '\n' << blue << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
