#include <iostream>
using namespace std;

int main(void)
{
    int arr[6][2] = {0}, n, k, result = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int gender, grade;
        cin >> gender >> grade;
        arr[grade - 1][gender]++;
    }
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            result += arr[i][j] / k;
            if(arr[i][j] % k != 0) result++;
        }
    }
    cout << result;
}