#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int arr[20], repeat = 0;
    for(int i = 0; i < 20; i++) arr[i] = i + 1;
    while(repeat < 10)
    {
        int a, b;
        cin >> a >> b;
        reverse(arr + a - 1, arr + b);
        repeat++;
    }
    for(int i = 0; i < 20; i++) cout << arr[i] << " ";
}