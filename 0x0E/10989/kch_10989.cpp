#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, input[10001] = {0,};
    cin >> num;
    for(int i = 0; i < num; i++) 
    {
        int in;
        cin >> in;
        input[in]++;
    }
    for(int i = 1; i < 10001; i++)
        for(int j = 0; j < input[i]; j++) 
            cout << i << "\n";
}
