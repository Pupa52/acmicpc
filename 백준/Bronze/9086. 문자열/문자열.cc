#include <iostream>
#include <string>

using namespace std;

void solution()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		string input;
		cin >> input;

		cout << input.front() << input.back() << endl;
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
