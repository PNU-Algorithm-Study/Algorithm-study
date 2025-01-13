#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
stack<pair<int, int> > building;

int main() 
{
    int num, h, height;
    cin >> num;
    for (int i = 0; i < num; i++) 
    {
        cin >> h;
        s.push(h);
    }
    int count, total = 0;
    while (!s.empty()) 
    {
        height = s.top();
        s.pop();
        count = 0;
        while (!building.empty()) 
        {
            if (height > building.top().first) 
            {
                count += building.top().second;
                count++;
                building.pop();
            }
            else break;
        }
        building.push(make_pair(height, count));
        total += count;
    }
    cout << total;
}