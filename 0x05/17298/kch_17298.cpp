#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int arr[1000001], result[1000001];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = n - 1; i >= 0 ; i--)
    {
        while(!s.empty() && s.top() <= arr[i]) s.pop();
        if(s.empty()) result[i] = -1;
        else result[i] = s.top();
        s.push(arr[i]);
    }
    for(int i = 0; i < n; i++) cout << result[i] << " ";
}
