#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution()
{
	string input;
	cin >> input;

	vector<int> alphabet(26, 0);
	for (auto chr : input)
	{
		char temp = toupper(chr);
		alphabet[temp - 'A'] += 1;
	}

	char result = '?';
	int max = -1;
	for (int i = 0; i < 26; i++)
	{
		if (max < alphabet[i])
		{
			max = alphabet[i];
			result = i + 'A';
		}

		else if (max == alphabet[i])
		{
			result = '?';
		}
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
