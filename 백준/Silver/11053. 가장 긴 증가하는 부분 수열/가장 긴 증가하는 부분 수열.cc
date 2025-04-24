#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	vector<int> seq(n);
	for (auto& iter : seq)
		cin >> iter;

	vector<int> length(n, 0);
	for (int i = 0; i < n; i++)
	{
		length[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (seq[j] < seq[i])
				length[i] = max(length[i], length[j] + 1);
		}
	}

	int result = 0;
	for (auto iter : length)
		result = max(result, iter);
	cout << result << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
