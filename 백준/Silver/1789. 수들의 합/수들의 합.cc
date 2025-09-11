#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	unsigned int s{}, n{};
	cin >> s;

	int index = 1;
	while (s >= index)
	{
		s -= index;
		index++;
		n++;
	}

	cout << n;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
