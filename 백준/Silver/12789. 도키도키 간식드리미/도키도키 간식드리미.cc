#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	int index = 1;

	stack<int> st;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		if (input == index)
			index++;

		else
		{
			while (!st.empty())
			{
				if (st.top() != index)
					break;
				index++;
				st.pop();
			}

			if (!st.empty() && st.top() < input)
			{
				cout << "Sad";
				return;
			}

			else
				st.push(input);
		}
	}

	cout << "Nice";
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
