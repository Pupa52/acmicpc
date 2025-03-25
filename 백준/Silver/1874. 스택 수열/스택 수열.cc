#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;

void solution()
{
	int n;
	cin >> n;

	vector<int> inputs, outputs;
	inputs.resize(n);
	outputs.reserve(n);
	for (auto& iter : inputs)
		cin >> iter;

	stack<int> buffer;
	stack<char> result;

	while (false == inputs.empty())
	{
		int value = inputs.back();

		if (true == buffer.empty())
		{
			buffer.push(value);
			inputs.pop_back();
			result.push('-');
		}

		else if (value > buffer.top())
		{
			buffer.push(value);
			inputs.pop_back();
			result.push('-');
		}

		else
		{
			outputs.push_back(buffer.top());
			buffer.pop();
			result.push('+');
		}
	}

	while (!buffer.empty())
	{
		outputs.push_back(buffer.top());
		buffer.pop();
		result.push('+');
	}

	for (int i = 0; i < outputs.size() - 1; i++)
	{
		if (outputs[i] < outputs[i + 1])
		{
			cout << "NO" << endl;
			return;
		}
	}

	while (!result.empty())
	{
		cout << result.top() << '\n';
		result.pop();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solution();

	return 0;
}
