#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int arr[9], max = 0, index = 0;
    for(int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        if(arr[i] > max)
        {
            max = arr[i];
            index = i;
        }
    }
    cout << max << endl << index + 1;
}