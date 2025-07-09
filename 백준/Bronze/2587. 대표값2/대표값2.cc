#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(int arr[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (arr[i] > arr[j])
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
	int arr[5] = {};
	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	int avg{};
	for (int i = 0; i < 5; i++)
		avg += arr[i];

	bubbleSort(arr);

	cout << avg / 5 << '\n';
	cout << arr[2];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}
