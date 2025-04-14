#include <iostream>

using namespace std;

int factorial(int x)
{
	int ret = 1;

	while (x > 0)
		ret *= x--;

	return ret;
}

void solution()
{
	int n, k;
	cin >> n >> k;

	cout << factorial(n) / (factorial(k) * factorial(n - k)) << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
