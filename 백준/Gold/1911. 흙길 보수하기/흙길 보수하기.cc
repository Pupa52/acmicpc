#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution()
{
	int answer = 0;

	int n, l;
	cin >> n >> l;

	vector<pair<int, int>> lines(n);
	for (auto& p : lines)
		cin >> p.first >> p.second;

	sort(lines.begin(), lines.end(), [](pair<int, int>& lhs, pair<int, int>& rhs){
		return lhs.first < rhs.first;
	});

	int en = -1;
	for (auto& line : lines)
	{
		if (en < line.first)
			en = line.first;

		while (true)
		{
			if (en >= line.second)
				break;

			en += l;
			answer++;
		}
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
