#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

void solution()
{
	int n;
	cin >> n;

	vector<int> numbers(n, 0);
	for (auto& iter : numbers)
		cin >> iter;

	set<int> addTwo;
	for (auto& first : numbers)
		for (auto& second : numbers)
			addTwo.insert(first + second);

	int maxValue = 0;
	for (auto& first : numbers)
	{
		for (auto& second : numbers)
		{
			auto iter = addTwo.find(first - second);
			if (addTwo.end() != iter)
				maxValue = maxValue < first ? first : maxValue;
		}
	}

	cout << maxValue << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
