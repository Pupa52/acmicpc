#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_number(char chr)
{
	return '0' <= chr && chr <= '9';
}

bool compare(const string& lhs, const string& rhs)
{
	if (lhs.size() == rhs.size())
		return lhs < rhs;

	return lhs.size() < rhs.size();
}

void solution()
{
	int n;
	cin >> n;

	vector<string> numbers;

	while (n-- > 0)
	{
		string str;
		cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			if (false == is_number(str[i]))
				continue;

			string number;

			int index = i;
			for (; index < str.size(); index++)
			{
				if (false == is_number(str[index]))
					break;

				number.push_back(str[index]);
			}

			if (number.size() > 1 && '0' == number[0])
			{
				int j = 0;
				for (; j < number.size() - 1; j++)
					if (number[j] != '0')
						break;

				number.erase(0, j);
			}

			numbers.push_back(number);
			i = index;
		}
	}

	sort(numbers.begin(), numbers.end(), compare);

	for (auto& str : numbers)
		cout << str << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
