#include <iostream>
#include <string>

#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <algorithm>
#include <memory>

#include <cstring>

#define MAX_LEN 256

using namespace std;


void solution()
{
	int n;
	cin >> n;

	vector<unsigned long long> fibo = {0, 1};
	fibo.resize(91, 0);

	for (int i = 2; i <= n; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	cout << fibo[n] << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
