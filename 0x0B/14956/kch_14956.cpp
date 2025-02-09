#include <iostream>
using namespace std;

int N, M, locX, locY;

void findLoc(int n, int m) {
    if(n == 2) { 
        locX = m < 2 ? 1 : 2;
        locY = (m == 0 || m == 3) ? 1 : 2;
        return;
    }
    n /= 2;
    findLoc(n, m % (n*n));
    switch (m / (n*n)) {
        int tmp;
        case 0:
            tmp = locX;
            locX = locY;
            locY = tmp;
            break;
        case 2:
            locX += n;
        case 1:
            locY += n;
            break;
        case 3:
            tmp = locY;
            locY = n + 1 - locX;
            locX = 2*n + 1 - tmp;
            break;
        default:
            throw;
    }
}

int main() {
    cin >> N >> M;
    findLoc(N, M-1);
    cout << locX << ' ' << locY;
}
