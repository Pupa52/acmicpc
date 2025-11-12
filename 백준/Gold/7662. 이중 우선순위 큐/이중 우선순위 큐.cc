#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solution()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int k;
		cin >> k;

		multiset<int> data;

		for (int i = 0; i < k; i++)
		{
			char cmd;
			int input;
			cin >> cmd >> input;

			if (cmd == 'I')
			{
				data.insert(input);
			}

			else if (!data.empty() && cmd == 'D')
			{
				auto iter = input == 1 ? --data.end() : data.begin();
				data.erase(iter);
			}
		}

		if (true == data.empty())
			cout << "EMPTY" << '\n';
		else
			cout << *(--data.end()) << ' ' << *(data.begin()) << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
