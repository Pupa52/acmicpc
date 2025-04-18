#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	vector<int> v(n + 1, 0);
	v[1] = 1;

	for (int i = 2; i <= n; i++)
		v[i] = v[i - 1] + v[i - 2];

	cout << v.back() << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
