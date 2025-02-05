#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;

int main(void)
{
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(pair<int, int>(a, b));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < num; i++) cout << v[i].first << ' ' << v[i].second << '\n';
}
