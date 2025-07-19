#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

void solution()
{
	string input;
	cin >> input;

	unordered_set<string> st;
	for (int i = 1; i <= input.size(); i++)
	{
		for (int j = 0; j <= input.size() - i; j++)
		{
			st.emplace(input.substr(j, i));
		}
	}

	cout << st.size();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
