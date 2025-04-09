#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

void solution()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int axisX = x < w - x ? x : w - x;
	int axisY = y < h - y ? y : h - y;

	cout << min(axisX, axisY) << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
