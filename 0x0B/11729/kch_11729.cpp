#include <iostream>
#include <cmath>
using namespace std;

void HanoiTower(int num, int from, int by, int to)
{
    if(num == 1) cout << from << ' ' << to << '\n';
    else
    {
        HanoiTower(num - 1, from, to, by);
        cout << from << ' ' << to << '\n';
        HanoiTower(num - 1, by, from, to);
    }
}

int main(void)
{
    int num;
    cin >> num;
    cout << (int)pow(2, num) - 1 << '\n';
    HanoiTower(num, 1, 2, 3);

    return 0;
}
