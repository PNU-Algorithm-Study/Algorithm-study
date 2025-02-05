#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> m;
map<int, int> m2;

bool cmp(pair<int, int> v1, pair<int, int> v2)
{
    if(v1.second != v2.second) return v1.second > v2.second;
    else return m2[v1.first] < m2[v2.first];
}

int main(void)
{
    int n, c;
    cin >> n >> c;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        m[input]++;
        if(m2[input] == 0) m2[input] = i + 1;
    }
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    for(auto it: v)
    {
        for(int i = 0; i < it.second; i++) cout << it.first << '\n';
    }
}
