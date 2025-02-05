#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void)
{
	int t, n;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		bool flag(true), error(false);
		string cmd, arr, number, result;
		deque<int> dq;

		cin >> cmd >> n >> arr;

		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[j] >= '0' && arr[j] <= '9')
				number.push_back(arr[j]);
			else if (!number.empty())
			{
				dq.push_back(atoi(number.c_str()));
				number.clear();
			}
		}

		for (int j = 0; j < cmd.size(); j++)
		{
			if (cmd[j] == 'R')
				flag = !flag;
			else if (cmd[j] == 'D')
			{
				if (dq.empty())
				{
					error = !error;
					break;
				}

				if (flag)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}

		if (!error)
		{
			result.push_back('[');
			while (!dq.empty())
			{
				if (flag)
				{
					result.append(to_string(dq.front()));
					dq.pop_front();
				}
				else
				{
					result.append(to_string(dq.back()));
					dq.pop_back();
				}
				if (!dq.empty()) result.push_back(',');
			}
			result.push_back(']');
			cout << result << endl;
		}
		else
			cout << "error" << endl;
	}
	return 0;
}