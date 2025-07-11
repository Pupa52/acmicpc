#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	map<string, int, greater<string>> log;
	for (int i = 0; i < n; i++)
	{
		string name, state;
		cin >> name >> state;

		if (state[0] == 'e')
			log[name] += 1;
		else
			log[name] -= 1;
	}

	for (auto p : log)
		if (p.second % 2 == 1)
			cout << p.first << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
