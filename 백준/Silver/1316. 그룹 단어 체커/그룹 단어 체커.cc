#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(string& input) 
{
	vector<int> alpha(26, -1);
	for (int i = 0; i < input.size(); i++)
	{
		int index = input[i] - 'a';
		if (alpha[index] != -1 && alpha[index] + 1 != i)
			return false;

		alpha[index] = i;
	}

	return true;
}

void solution()
{
	int t;
	cin >> t;

	int cnt = 0;
	while (t-- > 0)
	{
		string input;
		cin >> input;

		if (true == check(input))
			cnt++;
	}
	cout << cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
