#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> v1, v2;
        int n, m, result = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            v1.push_back(input);
        }
        for(int i = 0; i < m; i++)
        {
            int input;
            cin >> input;
            v2.push_back(input);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(v1[i] <= v2[j]) break;
                result++;
            }
        }
        cout << result << '\n';
    }
}
