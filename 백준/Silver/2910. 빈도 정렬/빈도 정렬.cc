#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void solution()
{
	int n, c;
	cin >> n >> c;

	vector<int> data(n);
	for (int i = 0; i < n; i++)
		cin >> data[i];

	vector<int> seq;
	seq.reserve(n);

	unordered_map<int, int> umap;
	for (int i = 0; i < n; i++)
	{
		auto iter = umap.find(data[i]);
		if (iter == umap.end())
			seq.push_back(data[i]);

		umap[data[i]] += 1;
	}

	stable_sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
		return umap.find(lhs)->second > umap.find(rhs)->second;
		});

	for (int i = 0; i < seq.size(); i++)
	{
		for (int j = 0; j < umap[seq[i]]; j++)
			cout << seq[i] << ' ';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
