#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) cout << v[i] << '\n';

    return 0;
}
