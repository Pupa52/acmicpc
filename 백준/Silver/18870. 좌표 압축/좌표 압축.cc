#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solution()
{
	int n{};
	cin >> n;

	vector<int> pos(n, 0);
	map<int, int> sortedPos;

	for (auto& iter : pos)
	{
		cin >> iter;
		sortedPos.insert({ iter, 0 });
	}

	int index = 0;
	for (auto& pair : sortedPos)
		pair.second = index++;

	for (int i = 0; i < pos.size(); i++)
	{
		cout << sortedPos[pos[i]];
		if (i + 1 != pos.size())
			cout << ' ';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
