#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

const string bw = "BWBWBWBW";
const string wb = "WBWBWBWB";

int _strncmp(const char* fisrt, const char* second, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(fisrt + i) != *(second + i))
			count++;
	}
	return count;
}

void solution()
{
	int n, m, min = INT_MAX;
	cin >> n >> m;

	vector<string> board(n);
	for (auto& iter : board)
		cin >> iter;

	for (int i = 0; i < n - 7; i++)
	{
		for (int j = 0; j < m - 7; j++)
		{
			int countW = 0, countB = 0;

			bool isWhite = true;
			for (int k = 0; k < 8; k++)
			{
				const char* pLine = isWhite ? wb.c_str() : bw.c_str();
				countW += _strncmp(pLine, &board[i + k][j], 8);
				isWhite = !isWhite;
			}

			isWhite = false;
			for (int k = 0; k < 8; k++)
			{
				const char* pLine = isWhite ? wb.c_str() : bw.c_str();
				countB += _strncmp(pLine, &board[i + k][j], 8);
				isWhite = !isWhite;
			}

			int count = countW < countB ? countW : countB;
			min = count < min ? count : min;
		}
	}

	cout << min << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
