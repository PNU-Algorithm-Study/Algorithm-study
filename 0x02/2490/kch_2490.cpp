#include <iostream>
using namespace std;

int main(void)
{
    int repeat = 0;
    while(repeat < 3)
    {
        int arr[4], countB = 0, countD = 0;
        for(int i = 0; i < 4; i++)
        {
            cin >> arr[i];
            if(arr[i] == 0) countB++;
            else countD++;
         }
         if(countB == 1 && countD == 3) cout << "A" << endl;
         else if(countB == 2 && countD == 2) cout << "B" << endl;
         else if(countB == 3 && countD == 1) cout << "C" << endl;
         else if(countB == 4 && countD == 0) cout << "D" << endl;
         else if(countB == 0 && countD == 4) cout << "E" << endl;
         repeat++;
    }
}