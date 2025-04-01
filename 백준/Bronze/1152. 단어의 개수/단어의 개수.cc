#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

void solution()
{
	string str;
	getline(cin, str);

	int count = 0;

	bool flag = true;
	for (auto chr : str)
	{
		if (chr == ' ')
			flag = true;
		else if (true == flag)
		{
			count++;
			flag = false;
		}
	}

	cout << count << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
