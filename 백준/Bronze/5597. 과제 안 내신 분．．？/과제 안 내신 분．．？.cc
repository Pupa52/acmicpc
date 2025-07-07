#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solution()
{
	vector<int> arr(30 + 1, 0);
	for (int i = 0; i < 28; i++)
	{
		int index;
		cin >> index;

		arr[index] = 1;
	}

	for (int i = 1; i <= 30; i++)
		if (arr[i] == 0)
			cout << i << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
