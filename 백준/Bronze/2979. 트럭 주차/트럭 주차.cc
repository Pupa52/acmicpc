#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution()
{
	int a, b, c;
	cin >> a >> b >> c;

	vector<int> time(101, 0);
	for (int i = 0; i < 3; i++)
	{
		int st, en;
		cin >> st >> en;

		for (int j = st; j < en; j++)
			time[j]++;
	}

	int sum = 0;
	for (int i = 1; i < 101; i++)
	{
		if (time[i] == 1)
			sum += a;
		else if (time[i] == 2)
			sum += b * 2;
		else if (time[i] == 3)
			sum += c * 3;
	}

	cout << sum << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
