#include <iostream>
#include <string>

#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <algorithm>
#include <memory>

#include <cstring>

using namespace std;

pair<int, int> offsets[4] = {
	{-1,  0 },
	{ 1,  0},
	{ 0, -1},
	{ 0,  1}
};

bool InBound(int row, int col, int width, int height)
{
	return (0 <= row && row < height) && (0 <= col && col < width);
}

void solution()
{
	vector<int> numbers(5, 0);

	int sum = 0;

	for (auto& iter : numbers)
	{
		cin >> iter;
		
		sum += (iter * iter);
	}

	cout << sum % 10 << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
