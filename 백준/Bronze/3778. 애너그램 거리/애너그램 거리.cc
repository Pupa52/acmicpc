#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	cin.ignore();

	for (int j = 1; j <= t; j++)
	{

		string a, b;
		getline(cin, a);
		getline(cin, b);

		char alphaA[26] = {};
		char alphaB[26] = {};

		for (auto chr : a)
			alphaA[chr - 'a'] += 1;

		for (auto chr : b)
			alphaB[chr - 'a'] += 1;

		int total = 0;
		for (int i = 0; i < 26; i++)
		{
			total += (alphaA[i] > alphaB[i] ? alphaA[i] - alphaB[i] : alphaB[i] - alphaA[i]);
		}

		cout << "Case #" << j << ": " << total << '\n';
	}

	return 0;
}