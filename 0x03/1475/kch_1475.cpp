#include <iostream>
using namespace std;

int main() {
    int arr[10] = {0}, num, max = 0;
    cin >> num;
    while(num != 0)
    {
        int a = num % 10;
        arr[a]++;
        num /= 10;
    }
    for(int i = 0; i < 10; i++)
    {
        if(i == 6 || i == 9) continue;
        else
        {
            if(arr[i] > max) max = arr[i];
        }
    }
    int a = arr[6] + arr[9];
    if(max > (a / 2 + a % 2)) cout << max;
    else cout << a / 2 + a % 2;
}
