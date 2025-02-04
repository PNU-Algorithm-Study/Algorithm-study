#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, string>> v;

bool cmp(pair<int, string> p1, pair<int, string> p2)
{
    return p1.first < p2.first;
}

int main(void)
{
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < num; i++) cout << v[i].first << " " << v[i].second << '\n';

    return 0;
}
