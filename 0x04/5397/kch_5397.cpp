#include <iostream>
#include <list>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    while (n--) 
    {
        string keylogger;
        cin >> keylogger;
        list<char> v;
        auto cursor = v.begin();
        for (char c : keylogger) 
        {
            if (c == '<') 
            {
                if (cursor != v.begin()) cursor--; 
            } 
            else if (c == '>') 
            {
                if (cursor != v.end()) cursor++; 
            } 
            else if (c == '-') 
            {
                if (cursor != v.begin()) cursor = v.erase(--cursor); 
            } 
            else v.insert(cursor, c); 
        }
        for (char c : v) cout << c;
        cout << endl;
    }
}