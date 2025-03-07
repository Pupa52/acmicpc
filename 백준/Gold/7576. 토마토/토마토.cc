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
	int width, length, day = 0, zeroCnt = 0;
	cin >> width >> length;

	vector<short> tomato;
	tomato.resize(width * length, 0);

	vector<short> visit;
	visit.resize(width * length, 0);

	queue<int> q, buffer;
	for (int i = 0; i < tomato.size(); i++)
	{
		cin >> tomato[i];

		switch (tomato[i])
		{
		case 0:
			zeroCnt++;
			break;

		case 1:
			q.push(i);
			visit[i] = 1;
			break;
		}
	}

	while (false == q.empty() || false == buffer.empty())
	{
		if (true == q.empty())
		{
			day++;
			q.swap(buffer);
		}

		int value = q.front(); q.pop(); // index

		int x = value % width;
		int y = value / width;

		// left
		int next = value - 1;
		if (x - 1 >= 0 && -1 != tomato[next] && 0 == visit[next])
		{
			buffer.push(next);
			tomato[next] = visit[next] = 1;
			zeroCnt--;
		}

		// right
		next = value + 1;
		if (x + 1 < width && -1 != tomato[next] && 0 == visit[next])
		{
			buffer.push(next);
			tomato[next] = visit[next] = 1;
			zeroCnt--;
		}

		// up
		next = value - width;
		if (y - 1 >= 0 && -1 != tomato[next] && 0 == visit[next])
		{
			buffer.push(next);
			tomato[next] = visit[next] = 1;
			zeroCnt--;
		}

		// down
		next = value + width;
		if (y + 1 < length && -1 != tomato[next] && 0 == visit[next])
		{
			buffer.push(next);
			tomato[next] = visit[next] = 1;
			zeroCnt--;
		}
	}

	cout << (zeroCnt != 0 ? -1 : day) << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
