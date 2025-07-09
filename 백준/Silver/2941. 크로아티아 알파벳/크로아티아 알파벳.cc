#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution()
{
	string input;
	cin >> input;

	vector<string> strs = {
		"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="
	};

	int cnt = 0;
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < strs.size(); j++)
		{
			if (input[i] != strs[j][0])
				continue;

			bool isFlag = true;
			for (int k = 0; k < strs[j].length(); k++)
			{
				if (input[i + k] != strs[j][k])
				{
					isFlag = false;
					break;
				}
			}

			if (true == isFlag)
				i += strs[j].length() - 1;
		}

		cnt++;
	}

	cout << cnt << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
