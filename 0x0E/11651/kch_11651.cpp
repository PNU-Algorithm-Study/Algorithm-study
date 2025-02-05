#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;

bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    if(p1.second == p2.second) return p1.first < p2.first;
    else return p1.second < p2.second;
}

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
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < num; i++) cout << v[i].first << ' ' << v[i].second << '\n';
}
