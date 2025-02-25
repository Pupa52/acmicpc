#include <iostream>
#include <string>

#include <vector>
#include <queue>
#include <stack>

#include <algorithm>
#include <memory>

#define MAX_LEN 256

using namespace std;

typedef pair<int, int> pii;

void solution()
{
	int n;
	cin >> n;

	vector<int> vec;
	vec.resize(n, 0);

	for (auto& iter : vec)
		cin >> iter;

	sort(vec.begin(), vec.end(), less<int>());

	for (auto iter : vec)
		cout << iter << '\n';
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
