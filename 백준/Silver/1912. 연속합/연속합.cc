#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (auto& iter : v)
		cin >> iter;

	vector<int> dist(n);
	dist[0] = v[0];

	for (int i = 1; i < n; i++)
		dist[i] = max(dist[i - 1] + v[i], v[i]);

	int result = INT_MIN;
	for (auto iter : dist)
		result = max(result, iter);
	cout << result << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}

