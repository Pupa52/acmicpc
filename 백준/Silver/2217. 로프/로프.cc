#include <iostream>
#include <string>

#include <vector>
#include <queue>
#include <stack>

#include <algorithm>
#include <memory>

#define MAX_LEN 256

using namespace std;

typedef pair<int, int> pii;

void solution()
{
	int n;
	cin >> n;
	
	vector<short> vec;
	vec.reserve(100001);

	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		vec.push_back(value);
	}

	sort(vec.begin(), vec.end(), less<short>());

	int maxWeight = 0;
	for (int i = 0; i < n; i++)
	{
		int weight = vec[i] * (n - i);
		if (weight > maxWeight)
			maxWeight = weight;
	}

	cout << maxWeight << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
