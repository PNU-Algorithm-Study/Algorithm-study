#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

int main(void)
{
    int n, target, result = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
    cin >> target;
    for(int i = 0; i < n; i++)
    {
        if(v[i] == target) result++;
    }
    cout << result;
}