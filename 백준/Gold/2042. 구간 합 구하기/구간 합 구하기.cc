#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	else
		return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2)
							+ init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

void update(vector<long long>& tree, int node, int index, int start, int end, long long diff)
{
	if (index < start || index > end)
		return;

	tree[node] += diff;

	if (start != end)
	{
		update(tree, node * 2, index, start, (start+end) / 2, diff);
		update(tree, node * 2 + 1, index, (start + end) / 2 + 1, end, diff);
	}

}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	if (start > right || end < left)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	return sum(tree, node * 2, start, (start + end) / 2, left, right)
		+ sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, k, mode, result, h, size;
	long long diff;

	cin >> n >> m >> k;
	vector<long long> arr(n);

	h = (int)ceil(log2(n));
	size = (1 << (h + 1));

	vector<long long> tree(size);
	pair<long long, long long> p;

	for (int i = 0; i < n; i++) cin >> arr[i];

	init(arr, tree, 1, 0, n - 1);
	for (int i = 0; i < m + k; i++)
	{
		cin >> mode >> p.first >> p.second;
		if (mode == 1)
		{
			diff = p.second - arr[p.first - 1];
			arr[p.first - 1] = p.second;
			update(tree, 1, p.first - 1, 0, n - 1, diff);
		}
		else if (mode == 2)
		{
			cout << sum(tree, 1, 0, n - 1, p.first - 1, p.second - 1) << endl;
		}
	}

}