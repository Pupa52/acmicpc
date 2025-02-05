#include <iostream>

using namespace std;

int intLen(int n);
int f_abs(int n);

void rec(int arr[10], int n, int curr, int index, int len, int* min)
{
	if (index != 0 && f_abs(n - (curr)) + index < *min)
		*min = f_abs(n - (curr)) + index;
	if (index == len)
		return;
	else
	{
		curr *= 10;
		for (int j = 9; j >= 0; j--)
		{
			if (arr[j] != 1)
			{
				curr += j;
				rec(arr, n, curr, index + 1, len, min);
				curr -= j;
			}
		}
	}
}

int intLen(int n)
{
	int len(0);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return len;
}

int f_abs(int n)
{
	if (n < 0)
		return -1 * n;
	else
		return n;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, curr(0), temp, Nmin(0), Rmin = 0x7fffffff, result(0);
	int* arr = new int[10]();

	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		arr[temp] = 1;
	}

	Nmin = f_abs(n - 100);
	rec(arr, n, curr, 0, intLen(n) + 1, &Rmin);
	result = Nmin > Rmin ? Rmin : Nmin;
	cout << result << endl;

	delete[] arr;
	arr = nullptr;
	return 0;
}