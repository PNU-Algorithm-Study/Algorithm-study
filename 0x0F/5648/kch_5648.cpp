#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> v;

int main(void)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        reverse(input.begin(), input.end());
        v.push_back(stol(input));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) cout << v[i] << '\n';
}
