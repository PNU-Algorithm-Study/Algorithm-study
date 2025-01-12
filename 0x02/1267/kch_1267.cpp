#include <iostream>
using namespace std;

int main(void)
{
    int n, arr[20], sumY = 0, sumM = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sumY += (arr[i] / 30 + 1) * 10;
        sumM += (arr[i] / 60 + 1) * 15;
    }

    if(sumY < sumM) cout << "Y " << sumY;
    else if(sumY == sumM) cout << "Y M " << sumY; 
    else cout << "M " << sumM;
}