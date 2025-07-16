#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solution()
{
	int n, m;
	cin >> n >> m;

	priority_queue<int> box;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		box.push(temp);
	}

	for (int i = 0; i < m; i++)
	{
		int child;
		cin >> child;
		
		int front = box.top(); box.pop();
		front -= child;

		if (front < 0)
		{
			cout << 0;
			return;
		}

		else if (front > 0)
			box.push(front);
	}

	cout << 1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
