#include <iostream>
#include <string>

using namespace std;

void solution()
{
	while (!cin.eof())
	{
		string input;
		getline(cin, input);

		cout << input << endl;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
