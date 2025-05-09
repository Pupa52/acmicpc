#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void solution()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		map<string, int> clothes;
		for (int i = 0; i < n; i++)
		{
			string str, type;
			cin >> str >> type;

			clothes[type] += 1;
		}

		int total = 1;
		for (auto& p : clothes)
			total *= (p.second + 1);

		cout << total - 1 << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
