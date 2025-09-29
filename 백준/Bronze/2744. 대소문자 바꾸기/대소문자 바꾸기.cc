#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution()
{
	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] - 'a' < 0)
		{
			input[i] += 32;
		}

		else
		{
			input[i] -= 32;
		}
	}

	cout << input;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
