#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, score, p, temp, result(-1);

	cin >> n >> score >> p;
	vector<int> v(p);

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v[i] = temp;
	}

	if (n == p && !(score > v[n - 1]))
	{
		cout << -1 << endl;
		return 0;
	}
	
	for (int i = 0; i < v.size(); i++)
	{
		if (score >= v[i])
		{
			result = i + 1;
			break;
		}
	}

	cout << result << endl;
	return 0;
}