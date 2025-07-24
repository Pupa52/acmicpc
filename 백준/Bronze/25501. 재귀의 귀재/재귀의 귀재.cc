#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int cnt{};

int recursion(const char* s, int l, int r)
{
	cnt++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPallindrome(const char* s)
{
	return recursion(s, 0, strlen(s) - 1);
}

void solution()
{
	int t;
	cin >> t;
	string s;

	while (t-- > 0)
	{
		string s;
		cin >> s;

		cnt = 0;
		cout << isPallindrome(s.c_str()) << ' ' << cnt << endl;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
