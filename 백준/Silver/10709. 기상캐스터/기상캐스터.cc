#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution()
{
	int h, w;
	cin >> h >> w;

	vector<int> sky(h * w, -1);
	for (int i = 0; i < h; i++)
	{
		string cloud;
		cin >> cloud;

		for (int j = 0; j < cloud.size(); j++)
		{
			if (cloud[j] != 'c')
				continue;

			int index = i * w + j;
			sky[index] = 0;

			for (int k = j + 1; k < w; k++)
			{
				sky[i * w + k] = sky[i * w + k - 1] + 1;
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = i * w + j;
			cout << sky[index] << ' ';
		}
		cout << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
