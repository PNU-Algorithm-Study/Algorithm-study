#include <iostream>
using namespace std;

int main(void)
{
    int arr[7], oddSum = 0, oddMin = 100, noOdd = 0;
    for(int i = 0; i < 7; i++)
    {
        cin >> arr[i];
        if(arr[i] % 2 == 1){
            oddSum += arr[i];
            if(arr[i] < oddMin) oddMin = arr[i];
        }
        else noOdd++;
    }
    if(noOdd == 7) cout << "-1";
    else cout << oddSum << endl << oddMin;
}