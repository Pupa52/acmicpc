#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution()
{
	int result = 0;

	string str0, str1;
	cin >> str0 >> str1;

	int row = (int)str0.size();
	int col = (int)str1.size();

	vector<vector<int>> data(row + 1, vector<int>(col + 1, 0));
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (str0[i - 1] == str1[j - 1])
				data[i][j] = data[i - 1][j - 1] + 1;

			result = max(result, data[i][j]);
		}
	}

	cout << result << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
