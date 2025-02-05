#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, m = 0, tmp = 0;

    cin >> n;
    unordered_map<int, int> card;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        card[tmp]++;
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> tmp;
        cout << card[tmp] << " ";
    }
    return 0;
}
