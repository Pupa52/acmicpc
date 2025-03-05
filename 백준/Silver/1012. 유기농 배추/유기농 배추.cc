#include <iostream>
#include <string>

#include <vector>
#include <queue>
#include <stack>

#include <algorithm>
#include <memory>

#include <cstring>

#define MAX_LEN 256

using namespace std;

void solution()
{
	int width, height, k, result = 0;
	cin >> width >> height >> k;

	int maxLength = width * height;

	bool* pos = (bool*)malloc(sizeof(bool) * maxLength);
	memset(pos, 0, sizeof(bool) * maxLength);

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;

		pos[y * width + x] = 1;
	}

	for (int i = 0; i < maxLength; i++)
	{
		if (false == pos[i])
			continue;

		result++;

		queue<short> q;
		q.push(i);
		while (false == q.empty())
		{
			int index = q.front(); q.pop();
			if (false == pos[index])
				continue;

			int x = index % width;
			int y = index / width;

			// value
			pos[index] = false;

			// left
			if (x - 1 >= 0) q.push(index - 1);

			// right
			if (x + 1 < width) q.push(index + 1);

			// up
			if (y - 1 >= 0) q.push(index - width);

			// down
			if (y + 1 < height) q.push(index + width);
		}
	}

	cout << result << '\n';

	free(pos);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (0 < t--)
		solution();

	return 0;
}
