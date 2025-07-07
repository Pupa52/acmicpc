#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	for (int i = 0; i < n - 4; i += 4)
		cout << "long ";
	cout << "long int";
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
