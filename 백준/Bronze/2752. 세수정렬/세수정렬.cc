#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution()
{
	vector<int> arr(3);
	for (auto& iter : arr)
		cin >> iter;

	sort(arr.begin(), arr.end());

	for (auto iter : arr)
		cout << iter << ' ';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
