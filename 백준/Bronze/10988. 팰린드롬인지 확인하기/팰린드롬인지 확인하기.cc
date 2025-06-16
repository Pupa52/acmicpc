#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution()
{
	string str;
	cin >> str;

	int size = str.length();

	int pt1 = 0, pt2 = size - 1;

	int result = 1;
	for (int i = 0; i < size / 2; i++)
	{
		if (str[pt1 + i] != str[pt2 - i])
		{
			result = 0;
			break;
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
