#include <iostream>
#include <deque>
using namespace std;
deque<int> dq;

int main() 
{
    int n, m, result = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) dq.push_back(i);
    while(m--)
    {
        int input, index = 0;
        cin >> input;
        for(int i = 0; i < dq.size(); i++)
        {
            if(dq[i] == input) index = i;
        }
        if(index <= dq.size() / 2)
        {
            while(1)
            {
                if(dq.front() == input)
                {
                    dq.pop_front();
                    break;
                }
                dq.push_back(dq.front());
                dq.pop_front();
                result++;
            }
        }
        else
        {
            while(1)
            {
                if(dq.front() == input)
                {
                    dq.pop_front();
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                result++;
            }
        }
    }
    cout << result;
}
