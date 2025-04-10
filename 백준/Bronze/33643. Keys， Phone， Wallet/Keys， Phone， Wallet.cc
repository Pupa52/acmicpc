#include <iostream>
#include <string>
#include <set>

using namespace std;

using pii = pair<int, int>;

void solution()
{
	int n;
	cin >> n;

	set<string> items;

	while (n-- > 0)
	{
		string item;
		cin >> item;

		items.insert(item);
	}

	bool bKeys = items.end() == items.find("keys");
	bool bPhone = items.end() == items.find("phone");
	bool bWallet = items.end() == items.find("wallet");

	if (bKeys)
		cout << "keys" << endl;

	if (bPhone)
		cout << "phone" << endl;

	if (bWallet)
		cout << "wallet" << endl;

	if (!bKeys && !bPhone && !bWallet)
		cout << "ready" << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
