#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main(void)
{
    int n, x, result = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
    cin >> x;
    sort(v.begin(), v.end());
    
    int left = 0, right = n - 1;
    while(left < right)
    {
        if(v[left] + v[right] == x)
        {
            left++;
            right--;
            result++;
        }
        else if(v[left] + v[right] < x) left++;
        else right--;
    }
    cout << result;
}