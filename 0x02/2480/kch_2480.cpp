#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && b == c) cout << 10000 + a * 1000;
    else if (a == b) cout << 1000 + a * 100;
    else if (b == c || a == c) cout << 1000 + c * 100;
    else cout << max({a, b, c}) * 100;
}