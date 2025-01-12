#include <iostream>
using namespace std;

int main(void)
{
    int num[10] = {0,}, a, b, c;
    cin >> a >> b >> c;
    string multiple = to_string(a * b * c);
    for(int i = 0; i < multiple.length(); i++) num[int(multiple[i] - '0')]++;
    for(int i = 0; i < 10; i++) cout << num[i] << endl;
}