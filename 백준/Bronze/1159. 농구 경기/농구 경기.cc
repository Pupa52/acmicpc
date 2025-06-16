#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	vector<int> alphabet(26, 0);
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;

		alphabet[name[0] - 'a'] += 1;
	}

	int count = 0;
	for (int i = 0; i < alphabet.size(); i++)
	{
		if (alphabet[i] >= 5)
		{
			cout << (char)(i + 'a');
			count++;
		}
	}

	if (count == 0)
		cout << "PREDAJA" << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
