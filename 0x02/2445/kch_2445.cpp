#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++) cout << '*';
        for(int j = 2 * (n-i); j > 0; j--) cout << ' ';
        for(int j = 0; j < i; j++) cout << '*';
        cout << "\n";
    }
    for(int i = 1; i < n; i++){
        for(int j = n - i; j > 0; j--) cout << '*';
        for(int j = 0; j < 2*i; j++) cout << ' ';
        for(int j = n - i; j > 0; j--) cout << '*';
        cout << "\n";
    }
}