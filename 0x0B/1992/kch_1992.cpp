#include <iostream>
#include <string>
using namespace std;

int N;
int arr[65][65];

void divide(int y, int x, int n) {
    if(n==1) {
        cout << arr[y][x];
        return;
    }
    
    bool zero = true;
    bool one = true;
    for(int i=y; i<y+n; i++){
        for(int j=x; j<x+n; j++){
            if(arr[i][j] == 0) one = false;
            else if(arr[i][j] == 1) zero = false;
        }
    }
    
    if(zero){
        cout << 0;
    }
    else if(one){
        cout << 1;
    }
    else{
        cout << "(";
        divide(y, x, n/2);
        divide(y, x+(n/2), n/2);
        divide(y+(n/2), x, n/2);
        divide(y+(n/2), x+(n/2), n/2);
        cout << ")";
    }
}

int main() {
    cin >> N;
    for (int y=0; y<N; y++) {
        string s; cin >> s;
        for (int x=0; x<N; x++) {
            arr[y][x] = s[x]-'0';
        }
    }
    
    divide(0,0,N);
    return 0;
}
