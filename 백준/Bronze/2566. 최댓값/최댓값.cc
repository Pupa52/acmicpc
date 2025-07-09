#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	int result = 0;
	int row{}, col{};

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			int temp{};
			cin >> temp;

			if (temp >= result)
			{
				result = temp;
				row = i;
				col = j;
			}
		}
	}

	cout << result << endl;
	cout << row << ' ' << col << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
