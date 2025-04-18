#include <iostream>
#include <vector>

using namespace std;

typedef struct _int2 {
	int _x;
	int _y;

public:
	_int2() : _x(0), _y(0) {};
	_int2(int x, int y) : _x(x), _y(y) {};

	_int2 operator+(_int2& rhs) {
		return _int2(_x + rhs._x, _y + rhs._y);
	}
	_int2 operator-(_int2& rhs) {
		return _int2(_x - rhs._x, _y - rhs._y);
	}
}INT2;

int cross(const INT2& first, const INT2& second) {
	return (first._x * second._y - first._y * second._x);
}

void solution()
{
	INT2 points[3] = {};

	for (auto& iter : points)
		cin >> iter._x >> iter._y;

	int result = cross(points[1] - points[0], points[2] - points[1]);

	if (result == 0)
		cout << 0 << endl;
	else
		cout << (result > 0 ? 1 : -1) << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
