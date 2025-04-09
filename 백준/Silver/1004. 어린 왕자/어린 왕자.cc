#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include<climits>

using namespace std;

typedef long long ll;

typedef struct _point
{
	int _x;
	int _y;
	int _r;

	bool InBound(_point pt) {
		int distance = (pt._x - _x) * (pt._x - _x) + (pt._y - _y) * (pt._y - _y);
		if (distance <= (_r * _r))
			return true;

		return false;
	}
}POINT;

void solution()
{
	int t, n;
	cin >> t;

	while (t-- > 0)
	{
		POINT st{}, en{};

		cin >> st._x >> st._y >> en._x >> en._y;
		cin >> n;

		vector<POINT> points(n);
		for (auto& iter : points)
			cin >> iter._x >> iter._y >> iter._r;

		int result = 0;
		for (auto iter : points)
		{
			bool bSt = iter.InBound(st);
			bool bEn = iter.InBound(en);

			if ((true == bSt && false == bEn) ||
				(false == bSt && true == bEn))
				result++;
		}

		cout << result << endl;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
