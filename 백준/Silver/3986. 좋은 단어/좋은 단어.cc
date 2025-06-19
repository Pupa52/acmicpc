#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;

		if (word.size() % 2 == 1)
			continue;

		stack<char> st;
		for (int j = 0; j < word.size(); j++)
		{
			if (false == st.empty() && st.top() == word[j])
			{
				st.pop();
				continue;
			}
			st.push(word[j]);
		}

		if (true == st.empty())
			cnt++;
	}

	cout << cnt << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
