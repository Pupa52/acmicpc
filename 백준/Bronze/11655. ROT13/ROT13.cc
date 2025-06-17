#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution()
{
	string str;
	getline(cin, str);

	string result;
	for (int i = 0; i < str.size(); i++)
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			int temp = (str[i] - 'a' + 13) % 26;
			result.push_back(temp + 'a');
		}

		else if ('A' <= str[i] && str[i] <= 'Z')
		{
			int temp = (str[i] - 'A' + 13) % 26;
			result.push_back(temp + 'A');
		}

		else
		{
			result.push_back(str[i]);
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
