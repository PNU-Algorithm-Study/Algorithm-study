#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> v;

int main(void)
{
    int n, cnt = 0, max = 0;
    long long result = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    result = v[0];
    for(int i = 1; i < n; i++)
    {
        if(v[i - 1] == v[i]) 
        {
            cnt++;
            if(cnt > max)
            {
                max = cnt;
                result = v[i];
            }
        }
        else cnt = 0;
    }
    cout << result;
}
