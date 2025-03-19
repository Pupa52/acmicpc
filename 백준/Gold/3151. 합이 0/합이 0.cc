#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solution()
{
	ll result = 0;

	int n;
	cin >> n;

	vector<int> students(n);
	for (auto& iter : students)
		cin >> iter;

	auto st = students.begin();
	auto en = students.end();

	sort(st, en);

	for (int i = 0; i < students.size() - 2; i++)
	{
		if (students[i] > 0) break;

		for (int j = i + 1; j < students.size() - 1; j++)
		{
			int value = (students[i] + students[j]) * -1;
			result += (upper_bound(st + j + 1, en, value) -
				lower_bound(st + j + 1, en, value));
		}
	}

	cout << result << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
