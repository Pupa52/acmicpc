#include <iostream>
#include <vector>
#include <string>

using namespace std;

using pii = pair<int, int>;

void solution()
{
	while (true)
	{
		string input;
		getline(cin, input);

		if (0 == input.compare("***"))
			break;

		string Inv(input.rbegin(), input.rend());
		cout << Inv << endl;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
