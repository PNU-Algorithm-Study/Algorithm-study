#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;

bool cmp(string str1, string str2)
{
    return str1 < str2;
}

int main(void)
{
    string str;
    int n = 0;
    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        v.push_back(str.substr(n));
        n++;
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < str.length(); i++) cout << v[i] << '\n';
}
