#include <iostream>
using namespace std;

int main(void)
{
    long long a, b;
    cin >> a >> b;
    if(a == b)
    {
        cout << 0;
        return 0;
    }
    if(a > b) swap(a, b);
    cout << b - a - 1 << endl;
    for(long long i = a + 1; i < b; i++) cout << i << " ";
}