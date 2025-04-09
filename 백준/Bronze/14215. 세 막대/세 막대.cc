#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include<climits>

using namespace std;

typedef long long ll;

void solution()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (a < b)
		swap(a, b);

	if (a < c)
		swap(a, c);

	if (a >= b + c)
		cout << (b + c) * 2 - 1 << endl;
	else
		cout << a + b + c << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
