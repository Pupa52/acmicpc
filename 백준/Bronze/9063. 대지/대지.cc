#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include<climits>

using namespace std;

typedef long long ll;

void solution()
{
	int n;
	cin >> n;

	pair<int, int> minPoint{ INT_MAX, INT_MAX };
	pair<int, int> maxPoint{ INT_MIN, INT_MIN };

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		minPoint.first = x < minPoint.first ? x : minPoint.first;
		minPoint.second = y < minPoint.second ? y : minPoint.second;

		maxPoint.first = x > maxPoint.first ? x : maxPoint.first;
		maxPoint.second = y > maxPoint.second ? y : maxPoint.second;
	}

	int width = maxPoint.first - minPoint.first;
	int height = maxPoint.second - minPoint.second;

	cout << width * height << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
