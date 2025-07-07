#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution()
{
	int a, b, c;
	cin >> a >> b >> c;

	int result = 0;
	if (a == b && b == c)
	{
		result = 10000 + a * 1000;
	}

	else if (a == b || b == c || c == a)
	{
		int temp = a == b ? a : c;
		result = 1000 + temp * 100;
	}

	else
	{
		result = max({ a, b, c }) * 100;
	}

	cout << result << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
