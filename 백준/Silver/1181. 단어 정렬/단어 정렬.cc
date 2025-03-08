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

struct myOrder {
	bool operator() (const string& left, const string& right) const
	{
		if (left.size() == right.size())
		{
			for (int i = 0; i < left.size(); i++)
			{
				if (left[i] == right[i])
					continue;

				return left[i] < right[i];
			}
			return false;
		}

		return left.size() < right.size();
	}
};

void solution()
{
	int N;
	cin >> N;

	set<string, myOrder> words;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		words.insert(input);
	}

	for (auto iter : words)
		cout << iter << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
