#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	vector<int> paper(10000, 0);

	int Cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		for (int j = y; j < y + 10; j++)
		{
			for (int k = x; k < x + 10; k++)
			{
				int index = j * 100 + k;
				if (paper[index] == 0)
					Cnt++;

				paper[index] = 1;
			}
		}
	}

	cout << Cnt << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
