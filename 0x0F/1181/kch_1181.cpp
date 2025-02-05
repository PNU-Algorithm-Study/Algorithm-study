#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;

bool cmp(string str1, string str2)
{   
    if(str1.size() == str2.size()) return str1 < str2;
    else return str1.size() < str2.size();
}

int main(void)
{
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        string input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < num; i++)
    {
        if(v[i] == v[i + 1]) continue;
        else cout << v[i] << '\n';
    }
}
