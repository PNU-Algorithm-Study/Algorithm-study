#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > i; j--) cout << ' ';
        for(int j = 1; j <= 2*i + 1; j++) cout << '*';
        cout << "\n";
    }
}