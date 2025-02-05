#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	long long first, second;
	int mid = (start + end) / 2;

	if (start == end)
		return tree[node] = arr[start];
	else
	{
		first = init(arr, tree, node * 2, start, mid);
		second = init(arr, tree, node * 2 + 1, mid + 1, end);

		return tree[node] = first > second ? second : first;
	}
}

long long search(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	long long first, second;
	int mid = (start + end) / 2;

	if (left > end || start > right)
		return 0x7fffffff;
	if (left <= start && end <= right)
		return tree[node];

	first = search(tree, node * 2, start, mid, left, right);
	second = search(tree, node * 2 + 1, mid + 1, end, left, right);
	return first > second ? second : first;
}


int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, h, size;

	cin >> n >> m;
	h = (int)ceil(log2(n));
	size = 1 << (h + 1);

	vector<long long> arr(n);
	vector<long long> tree(size);
	pair<long long, long long> p;

	for (int i = 0; i < n; i++) cin >> arr[i];
	init(arr, tree, 1, 0, n - 1);

	for (int i = 0; i < m; i++)
	{
		cin >> p.first >> p.second;
		cout << search(tree, 1, 0, n - 1, p.first - 1, p.second - 1) << '\n';
	}

	return 0;
}