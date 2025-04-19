#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	string a = "0", b = "1";
	if (n == 0 || n == 1)
	{
		cout << (n == 0 ? a : b) << '\n';
		return;
	}

	for (int i = 2; i <= n; i++)
	{
		int lenA = a.size();
		int lenB = b.size();
		string zero(abs(lenA - lenB), '0');
		if (lenA > lenB)
			b = zero + b;
		else
			a = zero + a;

		string c;
		c.reserve(a.size());

		int carry = 0;
		for (int i = a.size(); i > 0; i--)
		{
			int value = (a[i - 1] - '0') + (b[i - 1] - '0') + carry;
			carry = value / 10;
			value %= 10;
			c.push_back(value + '0');
		}
		if (carry == 1)
			c.push_back(carry + '0');

		a = b;
		b = string(c.rbegin(), c.rend());
	}
	cout << b << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
