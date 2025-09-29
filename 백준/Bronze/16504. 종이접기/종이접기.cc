#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	long long sum{};

	int n{};
	cin >> n;

	int num{};
	for (int i = 0; i < n * n; i++)
	{
		cin >> num;
		sum += num;
	}

	cout << sum;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
