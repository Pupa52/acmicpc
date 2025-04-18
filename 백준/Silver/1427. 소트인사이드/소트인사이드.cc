#include <iostream>
#include <string>

using namespace std;

void solution()
{
	string str;
	cin >> str;

	int arr[10] = {};
	for (auto& chr : str)
		arr[chr - '0'] += 1;

	int sum = 0;
	for (int i = 9; i >= 0; i--)
	{
		while (arr[i]-- > 0)
		{
			sum *= 10;
			sum += i;
		}
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
