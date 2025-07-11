#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>

using namespace std;

void solution()
{
	int n, m;
	cin >> n >> m;

	unordered_set<string> dir;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		dir.insert(input);
	}

	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		string input;
		cin >> input;

		if (dir.end() != dir.find(input))
			cnt++;
	}

	cout << cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
