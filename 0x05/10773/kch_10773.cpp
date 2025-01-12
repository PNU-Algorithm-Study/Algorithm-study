#include <iostream>
#include <stack>
using namespace std;
stack<int> st;

int main(void)
{
    int num, sum = 0;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        int input;
        cin >> input;
        if(input == 0) st.pop();
        else st.push(input);
    }
    while(!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    cout << sum;
}