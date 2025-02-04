#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int> st;
vector<char> vec;

int main(void)
{
    int num, n = 1;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        int input;
        cin >> input;
        while(n <= input)
        {
            st.push(n);
            n++;
            vec.push_back('+');
        }
        if(st.top() == input) 
        {
            st.pop();
            vec.push_back('-');
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << "\n";
}
