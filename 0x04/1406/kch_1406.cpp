#include <iostream>
#include <list>
using namespace std;

int main(void)
{
    string str;
    int n;
    cin >> str >> n;
    list<char> v(str.begin(), str.end());
    auto cursor = v.end();
    while(n--) 
    {
        string input;
        cin >> input;
        if (input == "L") 
        {
            if (cursor != v.begin()) cursor--;
        } 
        else if (input == "D") 
        {
            if (cursor != v.end()) cursor++;
        } 
        else if (input == "B") 
        {
            if (cursor != v.begin()) cursor = v.erase(--cursor);
        } 
        else if (input[0] == 'P') 
        {
            char x;
            cin >> x;
            v.insert(cursor, x);
        }
    }
    for (char c : v) cout << c;
}
