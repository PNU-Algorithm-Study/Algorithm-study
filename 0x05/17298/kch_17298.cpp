#include <iostream>
#include <stack>
using namespace std;
stack<int> st;

int main()
{
    int N;
    cin >> N;
    int arr[1000001];
    int answer[1000001];
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < N; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            answer[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        answer[st.top()] = -1;
        st.pop();
    }
    for (int i = 0; i < N; i++) cout << answer[i] << " ";
}