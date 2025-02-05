#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<string, int>> v;

bool cmp(pair<string, int> v1, pair<string, int> v2)
{
    if(v1.first.length() != v2.first.length()) return v1.first.length() < v2.first.length();
    else if(v1.second != v2.second) return v1.second < v2.second;
    else return v1.first < v2.first;
}

int main(void)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string input;
        int sum = 0;
        cin >> input;
        for(int j = 0; j < input.length(); j++) 
            if(input[j] >= '0' && input[j] <= '9') sum += int(input[j]) - 48;
        v.push_back(pair<string, int>(input, sum));
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++) cout << v[i].first << '\n';
}
