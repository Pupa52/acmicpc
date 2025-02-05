#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	string str;
	stack<char> sta;
	int tic = 0;

	while (true)
	{
		tic = 0;
		getline(cin, str);
		if (!str.compare("."))
			break;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
				sta.push(str[i]);
			else if (str[i] == ')' || str[i] == ']')
			{
				if (sta.empty())
				{
					sta.push(str[i]);
					break;
				}

				if (sta.top() == '(' && str[i] == ')')
					sta.pop();
				else if (sta.top() == '[' && str[i] == ']')
					sta.pop();
				else
					break;
			}
		}
		if (!sta.empty())
			cout << "no" << endl;
		else
			cout << "yes" << endl;
		while (!sta.empty()) sta.pop();
	}

	return 0;
}