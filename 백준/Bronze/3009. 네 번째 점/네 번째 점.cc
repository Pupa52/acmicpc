#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

void solution()
{
	vector<pair<int, int>> pos(3);
	for (auto& p : pos)
		cin >> p.first >> p.second;

	pair<int, int> total = make_pair(pos[0].first, pos[0].second);
	for (int i = 1; i < 3; i++)
	{
		if (total.first != pos[i].first)
		{
			total.first += pos[i].first;
			break;
		}
	}

	for (int i = 1; i < 3; i++)
	{
		if (total.second != pos[i].second)
		{
			total.second += pos[i].second;
			break;
		}
	}

	total.first *= 2;
	total.second *= 2;
	for (auto p : pos)
	{
		total.first -= p.first;
		total.second -= p.second;
	}

	cout << total.first << ' ' << total.second << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
