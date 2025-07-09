#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& arr)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void solution()
{
	int n, k;
	cin >> n >> k;

	vector<int> score(n);
	for (int i = 0; i < n; i++)
		cin >> score[i];

	sort(score.begin(), score.end(), greater<int>());

	cout << score[k - 1] << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
