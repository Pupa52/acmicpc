#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	string pattern;
	cin >> pattern;

	size_t index = pattern.find('*');

	while (n-- > 0)
	{
		string name;
		cin >> name;

		bool isFlag = false;
		if (name.size() < pattern.size() - 1)
			isFlag = true;

		for (int i = 0; i < index; i++)
		{
			if (pattern[i] != name[i])
			{
				isFlag = true;
				break;
			}
		}

		for (int i = 0; i < pattern.size() - index; i++)
		{
			if (pattern[pattern.size() - i] != name[name.size() - i])
			{
				isFlag = true;
				break;
			}
		}

		if (isFlag)	cout << "NE" << endl;
		else		cout << "DA" << endl;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
