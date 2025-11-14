#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;

		if (max_heap.size() > min_heap.size())
			min_heap.push(num);
		else
			max_heap.push(num);

		if (!max_heap.empty() && !min_heap.empty() && (max_heap.top() > min_heap.top()))
		{
			int temp0 = max_heap.top(); max_heap.pop();
			int temp1 = min_heap.top(); min_heap.pop();

			max_heap.push(temp1);
			min_heap.push(temp0);
		}

		if (i % 2 == 0)
			cout << min(max_heap.top(), min_heap.top()) << '\n';
		else
			cout << max_heap.top() << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
