#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll divAndConq(int a, int b, int c)
{
	if (b == 1)
		return a % c;

	ll k = divAndConq(a, b / 2, c);

	if (b % 2 == 0)
		return k * k % c;
	else
		return (k * k % c) * (a % c) % c;
}

void solution()
{
	int a, b, c;
	cin >> a >> b >> c;

	cout << divAndConq(a, b, c) << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
