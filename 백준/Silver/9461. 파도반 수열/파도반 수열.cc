#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	int t;
	cin >> t;

	vector<long long> seq = { 1, 1, 1, 2, 2 };
	for (int i = 5; i < 100; i++)
	{
		long long value = seq[i - 5] + seq[i - 1];
		seq.push_back(value);
	}

	while (t-- > 0)
	{
		int n;
		cin >> n;

		cout << seq[n - 1] << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}

